--Prepare audio buffer and drawing settings
local AUDIO_CHANNELS, AUDIO_SAMPLES
local samples_per_frame
local buffer
local waveheight
do
	--Audio meta data from clip
	local clip_info = USERDATA[1]:Info()
	AUDIO_CHANNELS = clip_info.channels
	AUDIO_SAMPLES = clip_info.samples
	local AUDIO_SAMPLE_RATE = clip_info.sample_rate

	--Audio buffer
	samples_per_frame = AUDIO_SAMPLE_RATE / VIDEO_FPS
	buffer = {}
	for channel_i=1, AUDIO_CHANNELS do
		buffer[channel_i] = {}
		local channel = buffer[channel_i]
		for sample_i=1, math.floor(samples_per_frame) * 3 do
			channel[sample_i] = 0
		end
	end

	--Drawing settings
	glLogicOp(GL_XOR)
	glLineWidth(0.5)
	waveheight = 0.1
end

function GetFrame(frame_index, frame_time)
	LoadFrameToContext()

	--Enough samples there for current frame?
	if math.floor(frame_index * samples_per_frame + samples_per_frame) <= AUDIO_SAMPLES then
		--Get samples from clip
		local frame_count = math.floor(samples_per_frame)
		local samples = USERDATA[1]:LoadSamples(math.floor(frame_index * samples_per_frame), frame_count)
		--Shift original samples in buffer forward to make place for new ones
		for channel_i, channel in ipairs(buffer) do
			for sample_i=1, #channel-frame_count do
				channel[sample_i] = channel[sample_i+frame_count]
			end
		end
		--Insert new samples in buffer
		for channel_i, channel in ipairs(buffer) do
			for sample_i=#channel-frame_count+1, #channel do
				channel[sample_i] = samples[1 + (sample_i-1) * AUDIO_CHANNELS + (channel_i-1)]
			end
		end
	end

	--Through buffer & draw
	for channel_i, channel in ipairs(buffer) do
		local y_offset = 1 - waveheight - (channel_i-1) * waveheight * 2
		glEnable(GL_COLOR_LOGIC_OP)
		glBegin(GL_LINE_STRIP)
		for sample_i, sample in ipairs(channel) do
			local x = -1 + 2 * (sample_i / #channel)
			local y = sample / 32768 * waveheight
			glVertex(x, y + y_offset)
		end
		glEnd()
		glDisable(GL_COLOR_LOGIC_OP)
	end

	SaveFrameFromContext()
end
