printpath("audio_info.txt")

print("Audio\n\tchannels: " .. AUDIO_CHANNELS .. "\n\tsample_rate: " .. AUDIO_SAMPLE_RATE .. "\n\tsamples: " .. AUDIO_SAMPLES .. "\n")

function GetSamples(start_sample_index, start_sample_time, count)
	print("Start sample " .. start_sample_index .. ": " .. start_sample_time .. "ms -> samples: " .. count)
end
