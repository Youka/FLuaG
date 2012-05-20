--[[
Outlines are often wished.
Using stencil buffer and different drawing modes makes it possible.
]]

--Triangle drawing list
local listbase = glGenLists(1)
do
	--Begin list
	glNewList(listbase, GL_COMPILE)
	--Enable blending for transparency
	glEnable(GL_BLEND)
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)
	--Using stencil buffer for non-overlapping drawing
	glClearStencil(0)
	glClear(GL_STENCIL_BUFFER_BIT)
	glStencilFunc(GL_NOTEQUAL, 1, 1)
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE)
	glEnable(GL_STENCIL_TEST)
	--Outline width
	glLineWidth(10)
	glPointSize(10)
	--Draw fill, bevel outline and outline rounds
	for _, job in ipairs({
							{mode = GL_TRIANGLES, color = {1, 1, 0, 0.5}},
							{mode = GL_LINE_LOOP, color = {1, 0, 0, 0.5}},
							{mode = GL_POINTS, color = {1, 0, 0, 0.5}}
						}) do
		glColor( unpack(job.color) )
		glBegin( job.mode )
			glVertex(0, 0.8)
			glVertex(0.8, -0.8)
			glVertex(-0.8, -0.8)
		glEnd()
	end
	--No more need for stenciling and blending
	glDisable(GL_STENCIL_TEST)
	glDisable(GL_BLEND)
	--Finish list
	glEndList()
end

function GetFrame(frame_index, frame_time)
	LoadFrameToContext()

	--Draw triangle
	glCallList(listbase)

	SaveFrameFromContext()
end
