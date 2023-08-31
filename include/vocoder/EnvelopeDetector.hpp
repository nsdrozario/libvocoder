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
#pragma once
#include "miniaudio.h"

#define ENVELOPE_MAX_FREQ 20 

// https://www.mathworks.com/help/dsp/ug/envelope-detection.html
namespace Vocoder {
    class EnvelopeDetector {
    private:

        ma_lpf1 low_pass_filter;

    public:
        EnvelopeDetector(unsigned long long sampleRate);
        ~EnvelopeDetector();

        // Returns the resulting sample
        float process_sample(float input);

    };
}