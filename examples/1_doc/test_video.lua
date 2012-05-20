glPointSize(USERDATA[1])

function GetFrame(frame_index, frame_ms)
    LoadFrameToContext()

	glBegin(GL_POINTS)
		glVertex(0,0)
	glEnd()

    SaveFrameFromContext()
end
