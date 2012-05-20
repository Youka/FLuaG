#pragma once

#include <windows.h>

class GLWindow
{
private:
	HINSTANCE hInstance;
	WNDCLASSEX wcx;

	HWND hwnd;
	HDC hdc;
	int pformat;
	PIXELFORMATDESCRIPTOR pfd;
	HGLRC cx;

	void CreateGLWindow(unsigned int w, unsigned int h, bool onscreen);
	void DestroyGLWindow();
	BOOL CheckMultisampling();

public:
	GLWindow(unsigned int w, unsigned int h, bool onscreen);
	~GLWindow(void);

	void InitGL(void);
	void CloseGL(void);
};
