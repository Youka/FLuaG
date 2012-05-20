--[[
For the beginning, let's make an image noise.
"GetFrame" is our entry function and allows us to have access to video frame data.
]]
function GetFrame(frame_index, frame_time)
	--First we get original frame data at current stream position.
	local frame = LoadFrame()

	--Now we pick a start pixel position.
	local pixel_i = math.random(1,4)
	--The iteration ends when we reach a pixel position out of frame.
	while pixel_i <= (#frame/4) do
		--For our current pixel position, we want to change all 3 'color' channels (RGB).
		for c=1, 3 do
			--We set current color channel to max value, so we produce a white pixel at the end.
			frame[1 + (pixel_i-1) * 4 + (c-1)] = 255
		end
		--Next we increment pixel position for next edit pass.
		pixel_i = pixel_i + math.random(1,4)
	end

	--Finally we push our changed data back to our stream.
	SaveFrame(frame)
end
