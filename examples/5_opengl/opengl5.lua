--[[
Creating objects in 3D with lightening.
Using GLU makes it easy to create complex objects without many calculation.
]]

--Initialize 3D room
glMatrixMode(GL_PROJECTION)
glLoadIdentity()
glOrtho(0, VIDEO_WIDTH, VIDEO_HEIGHT, 0, -1000, 1000)
glMatrixMode(GL_MODELVIEW)
glLoadIdentity()
glDepthFunc(GL_LEQUAL)
glClearDepth(1)

--Light (directional)
glLightModel(GL_LIGHT_MODEL_AMBIENT, {0, 0, 0, 0})
glLight(GL_LIGHT0, GL_AMBIENT, {0.1, 0.1, 0.1, 1})
glLight(GL_LIGHT0, GL_DIFFUSE, {1, 1, 1, 1})
glLight(GL_LIGHT0, GL_SPECULAR, {1, 1, 1, 1})
glLight(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.8)
glLight(GL_LIGHT0, GL_POSITION, {-1, -1, 0, 0})
glEnable(GL_LIGHT0)
glEnable(GL_LIGHTING)

--Material properties
glMaterial(GL_FRONT_AND_BACK, GL_SHININESS, 30)
glMaterial(GL_FRONT_AND_BACK, GL_SPECULAR, {1, 1, 1, 1})

--Objects data
local quad = gluNewQuadric()
local surface_points = {
	0, 0, 0, 100, 0, 0, 200, 0, 0,
	0, 100, 0, 100, 100, 1000, 200, 100, 0,
	0, 200, 0, 100, 200, 0, 200, 200, 0
}

function GetFrame(frame_index, frame_time)
	LoadFrameToContext()

	--Activate depth
	glClear(GL_DEPTH_BUFFER_BIT)
	glEnable(GL_DEPTH_TEST)

	--Sphere
	glPushMatrix()
	glTranslate(700, 300, 300)
	glMaterial(GL_FRONT_AND_BACK, GL_AMBIENT, {1, 0, 0, 1})
	glMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE, {1, 0, 0, 1})
	gluSphere(quad, 50, 100, 100)
	glPopMatrix()

	--Cone
	glPushMatrix()
	glTranslate(650, 450, 150)
	glRotate(20, 1, 0, 0)
	glMaterial(GL_FRONT_AND_BACK, GL_AMBIENT, {0, 1, 0, 1})
	glMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE, {0, 1, 0, 1})
	gluCylinder(quad, 40, 0, 100, 50, 50)
	glPopMatrix()

	--Partial disk
	glPushMatrix()
	glTranslate(600, 210, 0)
	glRotate(-50, 0, 1, 0)
	glScale(1, 1.5, 1)
	glMaterial(GL_FRONT_AND_BACK, GL_AMBIENT, {0, 0, 1, 1})
	glMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE, {0, 0, 1, 1})
	gluPartialDisk(quad, 10, 30, 100, 100, -70, 330)
	glPopMatrix()

	--Surface
	glPushMatrix()
	glTranslate(480, 300, 0)
	glRotate(45, 1, 0.5, 0)
	glMaterial(GL_FRONT_AND_BACK, GL_AMBIENT, {0.8, 0.8, 0.8, 1})
	glMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE, {0.8, 0.8, 0.8, 1})
	glEnable(GL_MAP2_VERTEX_3)
	glEnable(GL_AUTO_NORMAL)
	glMap(GL_MAP2_VERTEX_3,
			0, 1, 3, 3,
			0, 1, 9, 3,
			surface_points)
	glMapGrid(50, 0, 1, 50, 0, 1)
	glEvalMesh(GL_FILL, 0, 50, 0, 50)
	glDisable(GL_AUTO_NORMAL)
	glDisable(GL_MAP2_VERTEX_3)
	glPopMatrix()

	--Deactivate depth
	glDisable(GL_DEPTH_TEST)

	SaveFrameFromContext()
end
