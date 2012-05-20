--[[
Use of some FLuaG extensions to OpenGL.
Text drawing and convolution filter in an easy way.
]]

--Initialize 2D room
glMatrixMode(GL_PROJECTION)
glLoadIdentity()
gluOrtho2D(0, VIDEO_WIDTH, VIDEO_HEIGHT, 0)
glMatrixMode(GL_MODELVIEW)
glLoadIdentity()

--Constant color and position
glColor(1, 0, 0)
glTranslate(300, 200, 0)

--Save text creation
local listbase = glGenLists(1)
glNewList(listbase, GL_COMPILE)
gluDrawPath( flCreateFont("Arial", 80, true, true):getpath("My 2D text") )
glEndList()

function GetFrame(frame_index, frame_time)
	LoadFrameToContext()

	--Draw text
	glCallList(listbase)

	if frame_index < VIDEO_FRAMES/2 then
		--Blur fullscreen
		flConvolutionFilter(5, 5,{	--5x5 gaussian blur
			1/100, 2/100, 4/100, 2/100, 1/100,
			2/100, 4/100, 8/100, 4/100, 2/100,
			4/100, 8/100, 16/100, 8/100, 4/100,
			2/100, 4/100, 8/100, 4/100, 2/100,
			1/100, 2/100, 4/100, 2/100, 1/100
		})
	else
		--Fullscreen edge detection
		flConvolutionFilter(3, 3,{	--3x3 edge detection
			-1, -1, -1,
			-1,  8, -1,
			-1, -1, -1
		})
	end

	SaveFrameFromContext()
end
