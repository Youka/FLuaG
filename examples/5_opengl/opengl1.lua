--[[
Drawing an arc in 2D.
Interpolated colors let it appear as light source.
]]

--Initialize 2D room
glMatrixMode(GL_PROJECTION)
glLoadIdentity()
gluOrtho2D(0, VIDEO_WIDTH, VIDEO_HEIGHT, 0)
glMatrixMode(GL_MODELVIEW)
glLoadIdentity()

--Arc drawing parameters
local r = 50
local circ = math.ceil(2*math.pi*r)

function GetFrame(frame_index, frame_time)
	--Frame data to OpenGL
	LoadFrameToContext()

	--Let's move what we draw afterwards
	glLoadIdentity()
	glTranslate( (frame_index / VIDEO_FRAMES) * VIDEO_WIDTH, VIDEO_HEIGHT/2, 0)

	--Let's draw a light source
	glBegin(GL_TRIANGLE_FAN)
		--Middle; opaque white (=light source)
		glColor(1,1,1,1)
		glVertex(0,0)
		--Triangles slanted to arc outline; edges transparent black (=light shine)
		glColor(0,0,0,0)
		for i=0, circ do
			glVertex( math.ellipse(0, 0, 2*r, 2*r, i/circ * 360) )
		end
	glEnd()

	--From OpenGL back to stream
	SaveFrameFromContext()
end
