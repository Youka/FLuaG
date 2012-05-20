function GetSamples(start_sample_index, start_sample_ms, count)
    local samples = {}

    for i=1, count * AUDIO_CHANNELS do
        samples[i] = math.random(-32768, 32767)
    end

    SaveSamples(samples)
end
