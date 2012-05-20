# FLuaG
---
##Definition
**FLuaG** (*Floating Lua Graphics*) is an Avisynth plugin for video/audio data editing via Lua scripting.

Allowing to transfer image/sample data between Avisynth and Lua, it works like a filter SDK. Inside Lua scripts it's possible to write 3D effects with OpenGL or others things by importing libraries to the Lua API.
Regrettably FLuaG slows the process much more than an original filter in C/C++ but it makes the work easier.

##Features
* All in one file
* Video & audio access
* OpenGL 2.1 + GL_ARB_imaging + GL_ARB_framebuffer_object support
* Text extents & outline path
* PNG image loading & saving
* Math geometry functions
* Onscreen rendering

##Examples
**test.avs**

    BlankClip(length=250, width=704, height=396, pixel_type="RGB32", fps=25, audio_rate=48000, channels=2, sample_type="16bit")

    point_size = 50
    FLuaG(audio="test_audio.lua", video="test_video.lua", onscreen=false, samples32=false, userdata="point_size")
    
**test_audio.lua**

    function GetSamples(start_sample_index, start_sample_ms, count)
        local samples = {}

        for i=1, count * AUDIO_CHANNELS do
            samples[i] = math.random(-32768, 32767)
        end

        SaveSamples(samples)
    end
    
**test_video.lua**

    glPointSize(USERDATA[1])

    function GetFrame(frame_index, frame_ms)
        LoadFrameToContext()

        glBegin(GL_POINTS)
            glVertex(0,0)
        glEnd()

        SaveFrameFromContext()
    end
    
--

**test.avs:** using FLuaG on a blank clip to edit audio data by "test_audio.lua" and video data by "test_video.lua"

**test_audio.lua:** random noise

**test_video.lua:** point at mid