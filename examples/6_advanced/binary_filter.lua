--Data for processing
local x_step, y_step
local listbase
do
	--Save text dimensions
	local my_font = flCreateFont("Arial", 8, false, false)
	local fill_width, _, fill_ascent, fill_descent = my_font:textextents("0")
	local void_width, _, void_ascent, void_descent = my_font:textextents("1")
	x_step, y_step = math.ceil(math.max(fill_width, void_width)), math.ceil(math.max(fill_ascent+fill_descent, void_ascent+void_descent))

	--Display lists for text drawings
	listbase = glGenLists(2)
	glNewList(listbase, GL_COMPILE)
	gluDrawPath( my_font:getpath("0") )
	glEndList()
	glNewList(listbase+1, GL_COMPILE)
	gluDrawPath( my_font:getpath("1") )
	glEndList()

	--Initialize 2D room
	glMatrixMode(GL_PROJECTION)
	glLoadIdentity()
	gluOrtho2D(0, VIDEO_WIDTH, VIDEO_HEIGHT, 0)
	glMatrixMode(GL_MODELVIEW)
	glLoadIdentity()

	--Set colors
	glColor(0, 1, 0, 1)
	glClearColor(0, 0, 0, 1)
end

--Process
function GetFrame(frame_index, frame_ms)
	--Load video frame data
	local frame = LoadFrame()

	--Clear frame to background color
	glClear(GL_COLOR_BUFFER_BIT)
	--Loop through frame pixel chunks
	for y=0, VIDEO_HEIGHT-1, y_step do
		for x=0, VIDEO_WIDTH-1, x_step do
			--Set draw position
			glLoadIdentity()
			glTranslate(x, y, 0)
			local pixel_index = 1 + (VIDEO_HEIGHT - 1 - y) * VIDEO_WIDTH * 4 + x * 4
			--Text pixel grey value at current position: bright or dark?
			if ((frame[pixel_index] + frame[pixel_index+1] + frame[pixel_index+2]) / 3) <= 127 then
				--Draw fill
				glCallList(listbase)
			else
				--Draw void
				glCallList(listbase+1)
			end
		end
	end

	--Save created frame data
	SaveFrameFromContext()
end
