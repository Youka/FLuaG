--######################### CHECK ENGINE AVAILABILITY ##############################
if not glViewport then
	error("Missing OpenGL functions. Engine just available for video script!", 0)
end

--######################### UTILITIES ##############################
--Error handler
local function sg_error(msg)
	error(msg, 0)
end

--Render modes
local render_modes = {
	["Points"] = GL_POINTS,
	["Lines"] = GL_LINES,
	["Line strip"] = GL_LINE_STRIP,
	["Line loop"] = GL_LINE_LOOP,
	["Triangles"] = GL_TRIANGLES,
	["Triangle strip"] = GL_TRIANGLE_STRIP,
	["Triangle fan"] = GL_TRIANGLE_FAN,
	["Quads"] = GL_QUADS,
	["Quad strip"] = GL_QUAD_STRIP
}

--Light ID buffer
local light_buffer = {}
for i=1, glGetNumber(GL_MAX_LIGHTS, 1)[1] do
	light_buffer[i] = true
end

--Light preconfig
glLightModel(GL_LIGHT_MODEL_AMBIENT, {0, 0, 0, 0})
glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE)

--######################### FRAME LOOP FUNCTION (RENDER TO VIDEO) ##############################
function VideoFilter(render_func)
	if type(render_func) ~= "function" then
		sg_error("function for video filter expected")
	end

	function GetFrame(frame_index, frame_time)
		LoadFrameToContext()
		render_func(frame_index, frame_time)
		SaveFrameFromContext()
	end
end

--######################### GLScene ##############################
function GLScene(x, y, width, height)
	--Check
	if type(x) ~= "number" or
		type(y) ~= "number" or
		type(width) ~= "number" or
		type(height) ~= "number" or
		x < 0 or y < 0 or width <= 0 or height <= 0 then
		sg_error("x, y, width and height expected")
	end

	--Attributes
	local camera
	local nodes = {}

	--Methods
	local methods = {}
	methods.__index = methods

	function methods:setcamera(cam)
		if type(cam) ~= "table" or cam.type ~= "GLCamera" then
			sg_error("camera expected")
		end

		local last_cam = camera
		camera = cam
		return last_cam
	end

	function methods:attach(node, name)
		if node and (type(node) ~= "table" or node.type ~= "GLNode") or
			type(name) ~= "string" then
			sg_error("node/nil and name expected")
		end

		local last_node = nodes[name]
		nodes[name] = node
		return last_node
	end

	function methods:render()
		if not camera then
			sg_error("camera required")
		end

		local viewport = glGetNumber(GL_VIEWPORT, 4)
		glViewport(x, y, width, height)

		camera()
		glEnable(GL_BLEND)
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)

		for node_i, node in pairs(nodes) do
			node()
		end

		glDisable(GL_BLEND)
		camera()

		glViewport(unpack(viewport))
	end

	--Constructor
	return setmetatable({type="GLScene"}, methods)
end

--######################### GLCamera ##############################
function GLCamera(mode, depth, zoom)
	--Check
	if type(mode) ~= "string" or (mode ~= "2D" and mode ~= "3D") then
		sg_error("valid mode expected")
	elseif mode == "3D" then
		if type(depth) ~= "number" or depth < 1 or
			type(zoom) ~= "number" or zoom < 0 then
			sg_error("valid depth and zoom expected")
		end
	end

	--Attributes
	local on = false
	local position, direction, upvector = {0, 0, 0}, {0, 0, -1}, {0, 1, 0}

	--Methods
	local methods = {}
	methods.__index = methods

	function methods:adjust(pos, dir, up)
		if type(pos) ~= "table" or type(dir) ~= "table" or type(up) ~= "table" or
			#pos ~= 3 or #dir ~= 3 or #up ~= 3 then
			sg_error("position, direction and upvector expected")
		else
			for i, v in ipairs(pos) do
				if type(v) ~= "number" then
					sg_error("numbers in position expected")
				end
			end
			for i, v in ipairs(dir) do
				if type(v) ~= "number" then
					sg_error("numbers in direction expected")
				end
			end
			for i, v in ipairs(up) do
				if type(v) ~= "number" then
					sg_error("numbers in upvector expected")
				end
			end
		end

		local last_pos, last_dir, last_up = position, direction, upvector
		position, direction, upvector = table.copy(pos), table.copy(dir), table.copy(up)
		return last_pos, last_dir, last_up
	end

	methods.__call = function()
		if on then
			glMatrixMode(GL_PROJECTION)
			glLoadIdentity()

			glMatrixMode(GL_MODELVIEW)
			glLoadIdentity()

			if mode == "3D" then
				glDisable(GL_DEPTH_TEST)
			end
		else
			glMatrixMode(GL_PROJECTION)
			glLoadIdentity()

			local viewport = glGetNumber(GL_VIEWPORT, 4)
			if mode == "3D" then
				glMultMatrix({
					2/viewport[3], 0, 0, 0,
					0, -2/viewport[4], 0, 0,
					0, 0, 1/depth, -1/depth*zoom,
					-1, 1, 0, 1
				})
			else
				gluOrtho2D(0, viewport[3], viewport[4], 0)
			end

			glMatrixMode(GL_MODELVIEW)
			glLoadIdentity()

			if mode == "3D" then
				glDepthFunc(GL_GEQUAL)
				glClearDepth(0)
				glClear(GL_DEPTH_BUFFER_BIT)
				glEnable(GL_DEPTH_TEST)

				gluLookAt(
							position[1], position[2], position[3],
							direction[1], direction[2], direction[3],
							upvector[1], upvector[2], upvector[3]
						)
			end
		end

		on = not on
	end

	--Constructor
	return setmetatable({type="GLCamera"}, methods)
end

--######################### GLNode ##############################
function GLNode()
	--Attributes
	local entries = {}	--Nodes & objects

	--Methods
	local methods = {}
	methods.__index = methods

	function methods:attach(entry, name)
		if entry and (type(entry) ~= "table" or entry.type:sub(1,2) ~= "GL") or
			type(name) ~= "string" then
			sg_error("entry and name expected")
		end

		local last_entry = entries[name]
		entries[name] = entry
		return last_entry
	end

	methods.__call = function()
		--Activate transformations
		for entry_i, entry in pairs(entries) do
			if entry.type == "GLTransformation" then
				entry()
			end
		end
		--Activate properties
		for entry_i, entry in pairs(entries) do
			if entry.type == "GLColor" or
				entry.type == "GLLight" then
				entry()
			end
		end
		--Draw objects
		for entry_i, entry in pairs(entries) do
			if entry.type == "GLObject" or
				entry.type == "GLText" or
				entry.type == "GLRenderList" then
				entry()
			end
		end
		--Call nodes
		for entry_i, entry in pairs(entries) do
			if entry.type == "GLNode" then
				entry()
			end
		end
		--Deactivate properties & transformations
		for entry_i, entry in pairs(entries) do
			if entry.type == "GLTransformation" or
				entry.type == "GLColor" or
				entry.type == "GLLight" then
				entry()
			end
		end
	end

	--Constructor
	return setmetatable({type="GLNode"}, methods)
end

--######################### GLRenderList ##############################
function GLRenderList(draw_func)
	--Check
	if type(draw_func) ~= "function" then
		sg_error("function expected")
	end

	--Attributes
	local listbase = glGenLists(1)
	do
		glNewList(listbase, GL_COMPILE)
		draw_func()
		glEndList()
	end

	--Methods
	local methods = {}
	methods.__index = methods

	function methods:free()
		glDeleteLists(listbase, 1)
	end

	methods.__call = function()
		if glIsList(listbase) then
			glCallList(listbase)
		else
			sg_error("GLRenderList already freed")
		end
	end

	--Constructor
	return setmetatable({type="GLRenderList"}, methods)
end

--######################### GLText ##############################
function GLText(text, fontname, fontsize, bold, italic, depth)
	--Check
	if type(text) ~= "string" or
		type(fontname) ~= "string" or
		type(fontsize) ~= "number" or
		type(bold) ~= "boolean" or
		type(italic) ~= "boolean" or
		type(depth) ~= "number" or
		fontsize <= 0 or depth < 0 then
		sg_error("valid text, fontname, fontsize, bold, italic and depth expected")
	end

	--Attributes
	local font = flCreateFont(fontname, fontsize, bold, italic)
	local listbase = glGenLists(1)
	do
		local textpath = font:getpath(text)
		glNewList(listbase, GL_COMPILE)

		glNormal(0, 0, 1)
		gluDrawPath( textpath )

		if depth > 0 then
			for i, p in ipairs(textpath) do
				if p.type == GLU_MOVE then glBegin(GL_TRIANGLE_STRIP) end
				--Normal
				local nx, ny, nz
				if i == #textpath then
					nx, ny, nz = math.calcnormal(p.x, p.y, 0, p.x, p.y, -depth, textpath[i-1].x, textpath[i-1].y, 0)
				else
					nx, ny, nz = math.calcnormal(p.x, p.y, 0, p.x, p.y, -depth, textpath[i+1].x, textpath[i+1].y, 0)
				end
				glNormal(nx, ny, nz)
				--Front
				glVertex(p.x, p.y, 0)
				--Back
				glVertex(p.x, p.y, -depth)
				if p.type == GLU_ENDLINE then glEnd() end
			end

			glTranslate(0, 0, -depth)
			glNormal(0, 0, -1)
			gluDrawPath( textpath )
			glTranslate(0, 0, depth)
		end

		glEndList()
	end

	--Methods
	local methods = {}
	methods.__index = methods

	function methods:extents()
		return font:textextents(text), depth
	end

	function methods:free()
		glDeleteLists(listbase, 1)
	end

	methods.__call = function()
		if glIsList(listbase) then
			glCallList(listbase)
		else
			sg_error("GLText already freed")
		end
	end

	--Constructor
	return setmetatable({type="GLText"}, methods)
end

--######################### GLObject ##############################
function GLObject(mode, data)
	--Check
	if type(mode) ~= "string" or
		(mode ~= "Points" and
		mode ~= "Lines" and
		mode ~= "Line strip" and
		mode ~= "Line loop" and
		mode ~= "Triangles" and
		mode ~= "Triangle strip" and
		mode ~= "Triangle fan" and
		mode ~= "Quads" and
		mode ~= "Quad strip") then
		sg_error("valid mode expected")
	end
	if type(data) ~= "table" then
		sg_error("data table expected")
	else
		--Vertices
		if type(data.vertices) ~= "table" then
			sg_error("vertices expected")
		else
			for i, v in ipairs(data.vertices) do
				if type(v) ~= "table" or #v < 2 or #v > 4 then
					sg_error("vertex size 2-4 expected")
				else
					for ii, vv in ipairs(v) do
						if type(vv) ~= "number" then
							sg_error("numbers for vertex expected")
						end
					end
				end
			end
		end
		--Texture coordinates
		if data.tex_coords then
			if type(data.tex_coords) ~= "table" then
				sg_error("texture coordinates as table expected")
			else
				for i, v in ipairs(data.tex_coords) do
					if type(v) ~= "table" or #v < 1 or #v > 4 then
						sg_error("texture coordinate size 1-4 expected")
					else
						for ii, vv in ipairs(v) do
							if type(vv) ~= "number" then
								sg_error("numbers for texture coordinate expected")
							end
						end
					end
				end
			end
		end
		--Colors
		if data.colors then
			if type(data.colors) ~= "table" then
				sg_error("colors as table expected")
			else
				for i, v in ipairs(data.colors) do
					if type(v) == "table" and (#v == 3 or #v == 4) then
						for ii, vv in ipairs(v) do
							if type(vv) ~= "number" then
								sg_error("numbers for color expected")
							end
						end
					elseif type(v) ~= "boolean" then
						sg_error("color size 2-4 or boolean expected")
					end
				end
			end
		end
		--Normals
		if data.normals then
			if type(data.normals) ~= "table" then
				sg_error("normals as table expected")
			else
				for i, v in ipairs(data.normals) do
					if type(v) == "table" and #v == 3 then
						for ii, vv in ipairs(v) do
							if type(vv) ~= "number" then
								sg_error("numbers for normal expected")
							end
						end
					elseif type(v) ~= "boolean" then
						sg_error("normal size 3 or boolean expected")
					end
				end
			end
		end
		--Size (for points and lines)
		if data.size and (type(data.size) ~= "number" or data.size <= 0) then
			sg_error("size as valid number expected")
		end
	end

	--Attributes
	local mesh = table.copy(data)
	local texture

	--Methods
	local methods = {}
	methods.__index = methods

	function methods:bindtexture(tex)
		if type(tex) ~= "table" or tex.type ~= "GLTexture" then
			sg_error("texture expected")
		end

		local last_tex = texture
		texture = tex
		return last_tex
	end

	function methods:setvertices(vertices)
		if type(vertices) ~= "table" then
			sg_error("vertices expected")
		else
			for i, v in ipairs(vertices) do
				if type(v) ~= "table" or #v < 2 or #v > 4 then
					sg_error("vertex size 2-4 expected")
				else
					for ii, vv in ipairs(v) do
						if type(vv) ~= "number" then
							sg_error("numbers for vertex expected")
						end
					end
				end
			end
		end

		local last_vertices = mesh.vertices
		mesh.vertices = table.copy(vertices)
		return last_vertices
	end

	function methods:settex_coords(tex_coords)
		if type(tex_coords) ~= "table" then
			sg_error("texture coordinates as table expected")
		else
			for i, v in ipairs(tex_coords) do
				if type(v) ~= "table" or #v < 1 or #v > 4 then
					sg_error("texture coordinate size 1-4 expected")
				else
					for ii, vv in ipairs(v) do
						if type(vv) ~= "number" then
							sg_error("numbers for texture coordinate expected")
						end
					end
				end
			end
		end

		local last_tex_coords = mesh.tex_coords
		mesh.tex_coords = table.copy(tex_coords)
		return last_tex_coords
	end

	function methods:setcolors(colors)
		if type(colors) ~= "table" then
			sg_error("colors as table expected")
		else
			for i, v in ipairs(colors) do
				if type(v) == "table" and (#v == 3 or #v == 4) then
					for ii, vv in ipairs(v) do
						if type(vv) ~= "number" then
							sg_error("numbers for color expected")
						end
					end
				elseif type(v) ~= "boolean" then
					sg_error("color size 2-4 or boolean expected")
				end
			end
		end

		local last_colors = mesh.colors
		mesh.colors = table.copy(colors)
		return last_colors
	end

	function methods:setnormals(normals)
		if type(normals) ~= "table" then
			sg_error("normals as table expected")
		else
			for i, v in ipairs(normals) do
				if type(v) == "table" and #v == 3 then
					for ii, vv in ipairs(v) do
						if type(vv) ~= "number" then
							sg_error("numbers for normal expected")
						end
					end
				elseif type(v) ~= "boolean" then
					sg_error("normal size 3 or boolean expected")
				end
			end
		end

		local last_normals = mesh.normals
		mesh.normals = table.copy(normals)
		return last_normals
	end

	function methods:setsize(size)
		if type(size) ~= "number" or size <= 0 then
			sg_error("size as valid number expected")
		end

		local last_size = mesh.size
		mesh.size = size
		return last_size
	end

	methods.__call = function()
		if mesh.size then
			if mode == "Points" then
				glPointSize(mesh.size)
			elseif mode:sub(1,4) == "Line" then
				glLineWidth(mesh.size)
			end
		end

		local global_color = glGetNumber(GL_CURRENT_COLOR, 4)
		local global_normal = glGetNumber(GL_CURRENT_NORMAL, 3)

		if texture then
			texture()
			glEnable(GL_TEXTURE_2D)
		end

		glBegin(render_modes[mode])

		for i, vertex in ipairs(mesh.vertices) do
			if mesh.tex_coords and mesh.tex_coords[i] then
				glTexCoord(unpack(mesh.tex_coords[i]))
			end
			if mesh.colors and mesh.colors[i] ~= nil then
				local color = mesh.colors[i]
				if color == false then
					glColor(unpack(global_color))
				elseif color ~= true then
					glColor(unpack(color))
				end
			end
			if mesh.normals and mesh.normals[i] ~= nil then
				local normal = mesh.normals[i]
				if normal == false then
					glNormal(unpack(global_normal))
				elseif normal ~= true then
					glNormal(unpack(normal))
				end
			end
			glVertex(unpack(vertex))
		end

		glEnd()

		if texture then
			glDisable(GL_TEXTURE_2D)
			texture()
		end

		glColor(unpack(global_color))
		glNormal(unpack(global_normal))
	end

	--Constructor
	return setmetatable({type="GLObject"}, methods)
end

--######################### GLColor ##############################
function GLColor(red, green, blue, alpha)
	--Check
	if type(red) ~= "number" or
		type(green) ~= "number" or
		type(blue) ~= "number" or
		(alpha and type(alpha) ~= "number") then
		sg_error("red, green, blue and optional alpha expected")
	end

	--Attributes
	local last_color

	--Methods
	local methods = {}
	methods.__index = methods

	function methods:set(r, g, b, a)
		if type(r) ~= "number" or
			type(g) ~= "number" or
			type(b) ~= "number" or
			(a and type(a) ~= "number") then
			sg_error("red, green, blue and optional alpha expected")
		end

		local last_r, last_g, last_b, last_a = red, green, blue, alpha
		red, green, blue, alpha = r, g, b, a
		return last_r, last_g, last_b, last_a
	end

	methods.__call = function()
		if last_color then
			glColor(unpack(last_color))
			last_color = nil
		else
			last_color = glGetNumber(GL_CURRENT_COLOR, 4)
			if alpha then
				glColor(red, green, blue, alpha)
			else
				glColor(red, green, blue)
			end
		end
	end

	--Constructor
	return setmetatable({type="GLColor"}, methods)
end

--######################### GLTransformation ##############################
function GLTransformation(matrix)
	--Check
	if matrix then
		if type(matrix) ~= "table" or #matrix ~= 16 then
			sg_error("matrix expected")
		end
		for i, v in ipairs(matrix) do
			if type(v) ~= "number" then
				sg_error("numbers in matrix expected")
			end
		end
	end

	--Attributes
	local active = false
	local matrix_operations = {}
	if matrix then
		table.insert(matrix_operations, {op="m", table.copy(matrix)})
	end

	--Methods
	local methods = {}
	methods.__index = methods

	function methods:multiply(mat)
		if type(mat) ~= "table" or #mat ~= 16 then
			sg_error("matrix expected")
		end
		for i, v in ipairs(mat) do
			if type(v) ~= "number" then
				sg_error("numbers in matrix expected")
			end
		end

		table.insert(matrix_operations, {op="m", mat = table.copy(mat)})
		return self
	end

	function methods:reset()
		matrix_operations = {}
		return self
	end

	function methods:rotate(x, y, z)
		if type(x) ~= "number" or
			type(y) ~= "number" or
			type(z) ~= "number" then
			sg_error("x, y and z degree expected")
		end

		table.insert(matrix_operations, {op="r", x=x, y=y, z=z})
		return self
	end

	function methods:scale(x, y, z)
		if type(x) ~= "number" or
			type(y) ~= "number" or
			type(z) ~= "number" then
			sg_error("x, y and z factor expected")
		end

		table.insert(matrix_operations, {op="s", x=x, y=y, z=z})
		return self
	end

	function methods:translate(x, y, z)
		if type(x) ~= "number" or
			type(y) ~= "number" or
			type(z) ~= "number" then
			sg_error("x, y and z value expected")
		end

		table.insert(matrix_operations, {op="t", x=x, y=y, z=z})
		return self
	end

	methods.__call = function()
		if active then
			glPopMatrix()
		else
			if glGetNumber(GL_MODELVIEW_STACK_DEPTH, 1)[1] == glGetNumber(GL_MAX_MODELVIEW_STACK_DEPTH, 1)[1] then
				sg_error("too many transformations in row")
			end

			glPushMatrix()

			for i=1, #matrix_operations do
				local m_op = matrix_operations[i]
				if m_op.op == "m" then
					glMultMatrix(m_op.mat)
				elseif m_op.op == "r" then
					glRotate(m_op.x, 1, 0, 0)
					glRotate(m_op.y, 0, 1, 0)
					glRotate(m_op.z, 0, 0, 1)
				elseif m_op.op == "s" then
					glScale(m_op.x, m_op.y, m_op.z)
				elseif m_op.op == "t" then
					glTranslate(m_op.x, m_op.y, m_op.z)
				end
			end
		end

		active = not active
	end

	--Constructor
	return setmetatable({type="GLTransformation"}, methods)
end

--######################### GLLight ##############################
function GLLight(pos)
	--Check
	if type(pos) ~= "table" or #pos ~= 4 then
		sg_error("position expected")
	else
		for i, v in ipairs(pos) do
			if type(v) ~= "number" then
				sg_error("numbers for position expected")
			end
		end
	end

	--Attributes
	local id
	local position = table.copy(pos)
	local ambient = {0.1, 0.1, 0.1, 0.1}
	local diffuse = {1, 1, 1, 1}

	--Methods
	local methods = {}
	methods.__index = methods

	function methods:setambient(amb)
		if type(amb) ~= "table" or #amb ~= 4 then
			sg_error("ambient light expected")
		else
			for i, v in ipairs(amb) do
				if type(v) ~= "number" then
					sg_error("numbers for ambient light expected")
				end
			end
		end

		local last_ambient = ambient
		ambient = table.copy(amb)
		return last_ambient
	end

	function methods:setdiffuse(diff)
		if type(diff) ~= "table" or #diff ~= 4 then
			sg_error("diffuse light expected")
		else
			for i, v in ipairs(diff) do
				if type(v) ~= "number" then
					sg_error("numbers for diffuse light expected")
				end
			end
		end

		local last_diffuse = diffuse
		diffuse = table.copy(diff)
		return last_diffuse
	end

	function methods:setposition(pos)
		if type(pos) ~= "table" or #pos ~= 4 then
			sg_error("position expected")
		else
			for i, v in ipairs(pos) do
				if type(v) ~= "number" then
					sg_error("numbers for position expected")
				end
			end
		end

		local last_position = position
		position = table.copy(pos)
		return last_position
	end

	methods.__call = function()
		if id then
			--Deactivate light
			local light = _G["GL_LIGHT" .. (id-1)]
			glDisable(light)

			--Free light resource
			light_buffer[id] = true
			id = nil

			--Deactivate global lightning
			local no_light = true
			for i=1, #light_buffer do
				if not light_buffer[i] then
					no_light = false
					break
				end
			end

			if no_light then
				glDisable(GL_COLOR_MATERIAL)
				glDisable(GL_LIGHTING)
			end
		else
			--Get free light resource
			for i=1, #light_buffer do
				if light_buffer[i] then
					light_buffer[i] = false
					id = i
					break
				end
			end
			if not id then
				sg_error("lights limit overflow")
			end

			--Activate light
			local light = _G["GL_LIGHT" .. (id-1)]
			glEnable(light)

			--Light parameters
			glLight(light, GL_AMBIENT, ambient)
			glLight(light, GL_DIFFUSE, diffuse)
			glLight(light, GL_POSITION, position)

			--Activate global lightning
			glEnable(GL_LIGHTING)
			glEnable(GL_COLOR_MATERIAL)
		end
	end

	--Constructor
	return setmetatable({type="GLLight"}, methods)
end

--######################### GLTexture ##############################
function GLTexture(image)
	--Check
	if type(image) ~= "string" then
		sg_error("image filename expected")
	end

	--Attributes
	local activated = false
	local width, height = 0, 0
	local tex_id = glGenTextures(1)[1]
	do
		local result, img = pcall(flLoadPNG, image)
		if not result then
			sg_error("invalid image filename")
		end
		width, height = img.width, img.height
		glBindTexture(GL_TEXTURE_2D, tex_id)
		glTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
		glTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.width, img.height, 0, GL_RGBA, img)
		glBindTexture(GL_TEXTURE_2D, 0)
	end

	--Methods
	local methods = {}
	methods.__index = methods

	function methods:setimage(image)
		if type(img) ~= "string" then
			sg_error("image filename expected")
		end

		local result, img = pcall(flLoadPNG, image)
		if not result then
			sg_error("invalid image filename")
		end
		width, height = img.width, img.height
		glBindTexture(GL_TEXTURE_2D, tex_id)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.width, img.height, 0, GL_RGBA, img)
		glBindTexture(GL_TEXTURE_2D, 0)

		return self
	end

	function methods:getwidth()
		return width
	end

	function methods:getheight()
		return height
	end

	function methods:free()
		glDeleteTextures(1, {ted_id})
	end

	methods.__call = function()
		if activated then
			glBindTexture(GL_TEXTURE_2D, 0)
		else
			glBindTexture(GL_TEXTURE_2D, tex_id)
		end

		activated = not activated
	end

	--Constructor
	return setmetatable({type="GLTexture"}, methods)
end

--GLAdvancedObject

--GLProperties

--GLShader

--GLSurface

--GLFog
