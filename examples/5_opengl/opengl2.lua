--[[
Use of resources.
Drawing an image as texture.
]]

--Initialize 2D room
glMatrixMode(GL_PROJECTION)
glLoadIdentity()
gluOrtho2D(0, VIDEO_WIDTH, VIDEO_HEIGHT, 0)
glMatrixMode(GL_MODELVIEW)
glLoadIdentity()

--Load image into texture
local image = flLoadPNG("opengl2.png")
local tex = glGenTextures(1)[1]
glBindTexture(GL_TEXTURE_2D, tex)
glTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
glTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width, image.height, 0, GL_RGBA, image)

--Set full colors for original texture/image drawing
glColor(1, 1, 1, 1)

--Enabling blending for transparent parts of texture/image
glEnable(GL_BLEND)
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)

function GetFrame(frame_index, frame_time)
	LoadFrameToContext()

	--Draw texture/image
	glEnable(GL_TEXTURE_2D)
	glBegin(GL_QUADS)
		glTexCoord(0, 0); glVertex(0, 0)
		glTexCoord(1, 0); glVertex(image.width, 0)
		glTexCoord(1, 1); glVertex(image.width, image.height)
		glTexCoord(0, 1); glVertex(0, image.height)
	glEnd()
	glDisable(GL_TEXTURE_2D)

	SaveFrameFromContext()
end
