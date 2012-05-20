printpath("gl_info.txt")

print("###VERSIONS###")
print("GL: " .. glGetString(GL_VERSION))
print("GLU: " .. gluGetString(GLU_VERSION))
print("GLSL: " .. glGetString(GL_SHADING_LANGUAGE_VERSION))
print("FL: " .. flGetVersion())
print("")
print("###RENDERER###")
print(glGetString(GL_RENDERER) .. " by " .. glGetString(GL_VENDOR))
print("")
print("###ACTIVE###")
if GL_VERSION_2_1 then
	print("OpenGL 2.1")
elseif GL_VERSION_2_0 then
	print("OpenGL 2.0")
elseif GL_VERSION_1_5 then
	print("OpenGL 1.5")
elseif GL_VERSION_1_4 then
	print("OpenGL 1.4")
elseif GL_VERSION_1_3 then
	print("OpenGL 1.3")
elseif GL_VERSION_1_2 then
	print("OpenGL 1.2")
else
	print("OpenGL 1.1")
end
if GL_ARB_framebuffer_object then
	print("Framebuffer object")
end
if GL_ARB_imaging then
	print("Imaging")
end
print("")
print("###SUPPORTED EXTENSIONS###")
print("GL:\n" .. glGetString(GL_EXTENSIONS):gsub(" ", "\n"):gsub("([^\n]+)", "\t%1"))
print("GLU:\n" .. gluGetString(GLU_EXTENSIONS):gsub(" ", "\n"):gsub("([^\n]+)", "\t%1"))
