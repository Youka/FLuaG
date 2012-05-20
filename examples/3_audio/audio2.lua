--[[
Now we're producing our own sound.
It'll just be an annoying 'beep', but it's a beginning.
]]
function GetSamples(start_sample_index, start_sample_time, count)
	--First we prepare a buffer for all sample data.
	local sample_n = count * AUDIO_CHANNELS
    local samples = {[sample_n] = 0}

	--Here's the loop over all required samples.
	for i=1, count do
		for c=1, AUDIO_CHANNELS do
			--Time to put data into our buffer.
			--'sample_pos' stores our current sample position of this second in percent.
			--523 is the frequency, so the number of sinus waves per second.
			--32767 is the amplitude, so the volume of our sound.
			--At the end, it results in a high C tone.
			local sample_pos = math.mod(start_sample_index + (i-1), AUDIO_SAMPLE_RATE+1) / AUDIO_SAMPLE_RATE
			samples[1 + (i-1) * AUDIO_CHANNELS + (c-1)] = math.sin( sample_pos * math.pi * 2 * 523 ) * 32767
		end
	end

	--And finally we push our data to the stream.
	SaveSamples(samples)
end
