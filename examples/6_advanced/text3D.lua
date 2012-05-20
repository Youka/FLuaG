--Text drawing list
local listbase = glGenLists(1)
do
	--Text outline path and depth
	local text_path = flCreateFont("Times New Roman", 50, true, false):getpath("[Touhou] Bad apple")
	local depth = 50
	--Begin list
	glNewList(listbase, GL_COMPILE)
	--Save front text creation
	glNormal(0, 0, -1)
	gluDrawPath( text_path )
	--Save back text creation
	glPushMatrix()
	glTranslate(0, 0, depth)
	glNormal(0, 0, 1)
	gluDrawPath( text_path )
	glPopMatrix()
	--Save text sides creation
	for i, p in ipairs(text_path) do
		if p.type == GLU_MOVE then glBegin(GL_TRIANGLE_STRIP) end
		--Normal calculation
		local nx, ny, nz
		if i == #text_path then
			nx, ny, nz = math.calcnormal(p.x, p.y, 0, p.x, p.y, -depth, text_path[i-1].x, text_path[i-1].y, 0)
		else
			nx, ny, nz = math.calcnormal(p.x, p.y, 0, p.x, p.y, -depth, text_path[i+1].x, text_path[i+1].y, 0)
		end
		glNormal(nx, ny, nz)
		--Front binding
		glVertex(p.x, p.y, 0)
		--Back binding
		glVertex(p.x, p.y, depth)
		if p.type == GLU_ENDLINE then glEnd() end
	end
	--Finish list
	glEndList()
end

--Initialize 3D room
glMatrixMode(GL_PROJECTION)
glLoadIdentity()
glOrtho(0, VIDEO_WIDTH, VIDEO_HEIGHT, 0, -1000, 1000)
glMatrixMode(GL_MODELVIEW)
glLoadIdentity()
glDepthFunc(GL_LEQUAL)
glClearDepth(1)

--Light (point)
glLightModel(GL_LIGHT_MODEL_AMBIENT, {0, 0, 0, 0})
glLight(GL_LIGHT0, GL_AMBIENT, {0.1, 0.1, 0.1, 1})
glLight(GL_LIGHT0, GL_DIFFUSE, {1, 1, 1, 1})
glLight(GL_LIGHT0, GL_POSITION, {VIDEO_WIDTH/2, VIDEO_HEIGHT/2, 200, 1})
glEnable(GL_LIGHT0)
glEnable(GL_LIGHTING)

--Material color
glEnable(GL_COLOR_MATERIAL)
glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE)
glColor(1, 0, 0)

function GetFrame(frame_index, frame_time)
	LoadFrameToContext()

	--Activate depth
	glClear(GL_DEPTH_BUFFER_BIT)
	glEnable(GL_DEPTH_TEST)

	--Set rotation
	glLoadIdentity()
	glRotate(-7, 1, -1, 0)

	--Draw text
	glCallList(listbase)

	--Deactivate depth
	glDisable(GL_DEPTH_TEST)

	SaveFrameFromContext()
end
