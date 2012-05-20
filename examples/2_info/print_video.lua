printpath("video_info.txt")

print("Video\n\twidth: " .. VIDEO_WIDTH .. "\n\theight: " .. VIDEO_HEIGHT .. "\n\tfps: " .. VIDEO_FPS .. "\n\tframes: " .. VIDEO_FRAMES .. "\n")

function GetFrame(frame_index, frame_time)
	print("Frame " .. frame_index .. ": " .. frame_time .. "ms")
end
