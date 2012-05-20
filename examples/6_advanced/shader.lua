--Blur shader program
local prog
do
	--Create shaders
	local v_shad = glCreateShader(GL_VERTEX_SHADER)
	local f_shad = glCreateShader(GL_FRAGMENT_SHADER)
	glShaderSource(v_shad, [[
	varying vec2 tex_coord;

	void main(void)
	{
		gl_Position = ftransform();
		tex_coord = (gl_Position.xy + 1) * 0.5;
	}
	]])
	glShaderSource(f_shad, [[
	varying vec2 tex_coord;
	uniform sampler2D my_tex;
	uniform vec2 viewport;

	void main(void)
	{
		float x_step = 1.0/viewport.x;
		float y_step = 1.0/viewport.y;

		vec4 sum = vec4(0);
		float divisor = 0;
		float s, t;
		for(int y = -3; y <= 3; y++)
			for(int x = -3; x <= 3; x++){
				s = tex_coord.s + x * x_step;
				t = tex_coord.t + y * y_step;
				if(s >= 0 && s <= 1 && t >= 0 && t <= 1){
					sum += texture2D(my_tex, vec2(s, t));
					divisor++;
				}
			}

		gl_FragColor = sum / divisor;
	}
	]])
	glCompileShader(v_shad)
	glCompileShader(f_shad)
	--Create program and link shaders
	prog = glCreateProgram()
	glAttachShader(prog, v_shad)
	glAttachShader(prog, f_shad)
	glLinkProgram(prog)
end

--Texture for frame holding
local tex = glGenTextures(1)[1]
glBindTexture(GL_TEXTURE_2D, tex)
glTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
glTexParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)

function GetFrame(frame_index, frame_time)
	LoadFrameToContext()

	--Enable program for blurring
	glUseProgram(prog)

	--Frame to texture to fragment shader
	glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, VIDEO_WIDTH, VIDEO_HEIGHT, 0)
	glUniform(glGetUniformLocation(prog, "my_tex"), tex)
	--Frame/texture size to fragment shader
	glUniform(glGetUniformLocation(prog, "viewport"), VIDEO_WIDTH, VIDEO_HEIGHT)
	--Blur bottom frame half with 7x7 box blur program
	glRect(-1, 0, 1, -1)

	--Disable program for blurring
	glUseProgram(0)

	SaveFrameFromContext()
end
