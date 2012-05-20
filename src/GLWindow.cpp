#include "GLWindow.h"

//Multisampling informations
extern "C"{
#define WGL_DRAW_TO_WINDOW_ARB 0x2001
#define WGL_SUPPORT_OPENGL_ARB 0x2010
#define WGL_DOUBLE_BUFFER_ARB 0x2011
#define WGL_PIXEL_TYPE_ARB 0x2013
#define WGL_TYPE_RGBA_ARB 0x202B
#define WGL_COLOR_BITS_ARB 0x2014 
#define WGL_ALPHA_BITS_ARB 0x201B 
#define WGL_ACCUM_BITS_ARB 0x201D
#define WGL_DEPTH_BITS_ARB 0x2022 
#define WGL_STENCIL_BITS_ARB 0x2023
#define WGL_ACCELERATION_ARB 0x2003
#define WGL_FULL_ACCELERATION_ARB 0x2027
#define WGL_SAMPLE_BUFFERS_ARB 0x2041
#define WGL_SAMPLES_ARB 0x2042

typedef const char* (__stdcall *WGLGETEXTENSIONSSTRINGARBPROC) (HDC hdc);
WGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB = NULL;
typedef BOOL (WINAPI * PFNWGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = NULL;
}
//Window callback
LRESULT CALLBACK WndProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam){return DefWindowProc(hWnd, Message, wParam, lParam);}

//Window
GLWindow::GLWindow(unsigned int w, unsigned int h, bool onscreen){
	//Class
	hInstance = GetModuleHandle(NULL);
	wcx.cbSize = sizeof(WNDCLASSEX);
	wcx.style = CS_OWNDC;
	wcx.lpfnWndProc = WndProc;
	wcx.cbClsExtra = 0;
	wcx.cbWndExtra = 0;
	wcx.hInstance = hInstance;
	wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcx.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcx.lpszMenuName = NULL;
	wcx.lpszClassName = "FLuaG";
	wcx.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
	RegisterClassEx(&wcx);

	//Window
	CreateGLWindow(w, h, onscreen);

	//Pixelformat
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cAlphaBits = 8;
	pfd.cAccumBits = 32;
	pfd.cDepthBits = 16;
	pfd.cStencilBits = 8;
	pfd.iLayerType = PFD_MAIN_PLANE;

	//Set standard pixel format
	pformat = ChoosePixelFormat(hdc, &pfd);
	SetPixelFormat(hdc, pformat, &pfd);

	//Multisampling
	if(CheckMultisampling())
	{
		//New window
		DestroyGLWindow();
		CreateGLWindow(w, h, onscreen);
		//Enable FSAA
		UINT num;
		int valid;
		float fAttributes[] = {0, 0};
		int iAttributes[] = {WGL_DRAW_TO_WINDOW_ARB, 1,
			WGL_SUPPORT_OPENGL_ARB, 1,
			WGL_DOUBLE_BUFFER_ARB, 1,
			WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
			WGL_COLOR_BITS_ARB, 32,
			WGL_ALPHA_BITS_ARB, 8,
			WGL_ACCUM_BITS_ARB, 32,
			WGL_DEPTH_BITS_ARB, 16,
			WGL_STENCIL_BITS_ARB, 8,
			WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
			WGL_SAMPLE_BUFFERS_ARB, 1,
			WGL_SAMPLES_ARB, 16,
			0, 0};
		//16x AA
		valid = wglChoosePixelFormatARB(hdc, iAttributes, fAttributes, 1, &pformat, &num);
		if(!(valid && num >= 1))
		{
			//8x AA
			iAttributes[23] = 8;
			valid = wglChoosePixelFormatARB(hdc, iAttributes, fAttributes, 1, &pformat, &num);
			if(!(valid && num >= 1))
			{
				//4x AA
				iAttributes[23] = 4;
				valid = wglChoosePixelFormatARB(hdc, iAttributes, fAttributes, 1, &pformat, &num);
				if(!(valid && num >= 1))
				{
					//2x AA
					iAttributes[23] = 2;
					wglChoosePixelFormatARB(hdc, iAttributes, fAttributes, 1, &pformat, &num);
				}
			}
		}
		//Set pixel format
		SetPixelFormat(hdc, pformat, &pfd);
	}
	//My OpenGL context to current window
	cx = wglCreateContext(hdc);
}

void GLWindow::CreateGLWindow(unsigned int w, unsigned int h, bool onscreen)
{
	hwnd = CreateWindowEx(NULL, "FLuaG","FLuaG",WS_POPUP,
		0, 0, w, h,
		NULL, NULL, hInstance, NULL);

	if(!hwnd)
		throw "Unable to initialize opengl window!";

	if(onscreen)
		ShowWindow(hwnd, SW_SHOW);

	hdc = GetDC(hwnd);
	if (!hdc)
		throw "Unable to get opengl window context!";
}

void GLWindow::DestroyGLWindow()
{
	ReleaseDC(hwnd, hdc);
	DestroyWindow(hwnd);
}

GLWindow::~GLWindow(void)
{
	//Delete my OpenGL context
	CloseGL();
	wglDeleteContext(cx);
	//Destroy window
	DestroyGLWindow();
	UnregisterClass("FLuaG",hInstance);
}

BOOL GLWindow::CheckMultisampling()
{
	cx = wglCreateContext(hdc);
	if(!cx)
		throw "Unable to initialize opengl context!";
	wglMakeCurrent(hdc, cx);
	if(wglGetExtensionsStringARB = (WGLGETEXTENSIONSSTRINGARBPROC)wglGetProcAddress("wglGetExtensionsStringARB"))
	{
		if(strstr(wglGetExtensionsStringARB(this->hdc), "WGL_ARB_pixel_format") && strstr(wglGetExtensionsStringARB(this->hdc), "WGL_ARB_multisample"))
			wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
	}
	wglMakeCurrent(hdc, NULL);
	wglDeleteContext(cx);

	return (wglChoosePixelFormatARB != NULL);
}

void GLWindow::InitGL(void)
{
	if(wglGetCurrentContext() != NULL)
		CloseGL();
	wglMakeCurrent(hdc, cx);
}

void GLWindow::CloseGL(void)
{
	wglMakeCurrent(hdc, NULL);
}