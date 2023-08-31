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
#include <AudioFileReader.hpp>
#define MINIAUDIO_IMPLEMENTATION 
#include <miniaudio.h>
using namespace Vocoder;

AudioFileReader::AudioFileReader(std::string path) {
    // 0 should be native sample rate
    ma_decoder_config cfg = ma_decoder_config_init(ma_format_f32, 1, 44100);
    ma_decoder_init_file(path.c_str(), &cfg, &fileDecoder);
}

AudioFileReader::~AudioFileReader() {
    ma_decoder_uninit(&fileDecoder);
}

void AudioFileReader::close() {
    ma_decoder_uninit(&fileDecoder);
}

ma_decoder& AudioFileReader::getDecoderInstance() {
    return fileDecoder;
}

/*
 * Example:
 ```
 * AudioFileReader a ("file.mp3");
 * float current_sample = 0.0f; 
 * while (a.get_sample(&current_sample)) {
 *      // ...
 * }
 * a.close();
 * ```
*/
bool AudioFileReader::get_sample(float *output) {
    ma_uint64 read = 0;
    return ma_decoder_read_pcm_frames(&fileDecoder, output, 1, &read) == MA_SUCCESS;
}
