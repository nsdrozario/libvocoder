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
#include <EnvelopeDetector.hpp>

using namespace Vocoder;

EnvelopeDetector::EnvelopeDetector(unsigned long long sampleRate) {
    ma_lpf1_config cfg = ma_lpf1_config_init(
        ma_format_f32,
        1,
        sampleRate,
        ENVELOPE_MAX_FREQ
    );

    ma_lpf1_init(&cfg, nullptr, &low_pass_filter);
}

EnvelopeDetector::~EnvelopeDetector() {
}

float EnvelopeDetector::process_sample(float input) {
    float out = 0.0f;
    float in = input * input;
    ma_lpf1_process_pcm_frames(&low_pass_filter, &out, &in, 1);
    return out;
}