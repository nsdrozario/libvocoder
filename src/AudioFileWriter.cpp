/*
    This file is a part of libvocoder, a library for audio effects
    done using bandpass filter banks.
    Copyright (C) 2023 Nathaniel D'Rozario

    libvocoder is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include <vocoder/AudioFileWriter.hpp>
#include <miniaudio.h>
using namespace Vocoder;

AudioFileWriter::AudioFileWriter(std::string path, ma_uint32 sampleRate, ma_encoding_format format) {
    // 0 should be native sample rate
    ma_encoder_config cfg = ma_encoder_config_init(format, ma_format_f32, 1, sampleRate);
    ma_encoder_init_file(path.c_str(), &cfg, &fileEncoder);
}

AudioFileWriter::~AudioFileWriter() {
    ma_encoder_uninit(&fileEncoder);
}

void AudioFileWriter::close() {
    ma_encoder_uninit(&fileEncoder);
}

ma_encoder& AudioFileWriter::getEncoderInstance() {
    return fileEncoder;
}

/*
 * Example:
 ```
 * AudioFileWriter a ("file.mp3");
 * float current_sample = 0.0f; 
 * while (a.get_sample(&current_sample)) {
 *      // ...
 * }
 * a.close();
 * ```
*/
bool AudioFileWriter::write_sample(float input) {
    ma_uint64 framesWritten = 0;
    return ma_encoder_write_pcm_frames(&fileEncoder, &input, 1, &framesWritten) == MA_SUCCESS;
}
