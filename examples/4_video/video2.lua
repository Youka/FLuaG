--[[
Direct pixel data manipulation is very slow, so we're working with OpenGL now!
It's much faster and has functionality for all sorts of effects.
]]
function GetFrame(frame_index, frame_time)
	--Data transfer changed: frame data are directly copied to our OpenGL supporting surface.
	LoadFrameToContext()

	--Let's draw a quad
	glBegin(GL_QUADS)
		--Left-top corner; color: red
		glColor(1,0,0)
		glVertex(-0.5,0.5)
		--Right-top corner; color: yellow
		glColor(1,1,0)
		glVertex(0.5,0.5)
		--Right-bottom corner; color: green
		glColor(0,1,0)
		glVertex(0.5,-0.5)
		--Left-bottom corner; color: blue
		glColor(0,0,1)
		glVertex(-0.5,-0.5)
	glEnd()

	--Finally we transfer what's on our surface back to the stream.
	SaveFrameFromContext()
end
