--[[
For the beginning, let's mute one audio channel.
"GetSamples" is our audio entry function and allows us to have access to audio samples.
]]
function GetSamples(start_sample_index, start_sample_time, count)
	--First we get original sample data at current stream position.
	local samples = LoadSamples()

	--Now we pass each sample.
	for i=1, count do
		--Consider that multiple channels means multiple sample layers.
		for c=1, AUDIO_CHANNELS do
			--We choose channel one to work with.
			if c == 1 then
				--Now we access all samples of channel 1 and set their value to 0.
				--This means, there's no wave anymore = no sound.
				samples[1 + (i-1) * AUDIO_CHANNELS + (c-1)] = 0
			end
		end
	end

	--Finally we push our changed data back to our stream.
	SaveSamples(samples)
end
