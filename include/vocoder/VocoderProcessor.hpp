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
#include "FilterBank.hpp"
#include "EnvelopeDetector.hpp"
#include "VocoderFilterDistributor.hpp"
#include <vector>

namespace Vocoder {
    class VocoderProcessor {
    private:

        unsigned long long Fs;
        int n;
        float start;
        float end;

        VocoderFilterDistributor fd;
        FilterBank filterBank;
        FilterBank graphicEQ;

        std::vector<EnvelopeDetector> envelopes;
    
    public:
        
        VocoderProcessor(unsigned long long sampleRate, int nFilters, float start, float end);
        ~VocoderProcessor();

        float process_frame(float carrierInput, float modulatorInput);

    };
}