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
#include <VocoderProcessor.hpp>
using namespace Vocoder;

VocoderProcessor::VocoderProcessor(unsigned long long sampleRate, int nFilters, float start, float end) : 
    Fs(sampleRate), 
    n(nFilters), 
    start(start), 
    end(end), 
    fd(sampleRate, nFilters, start, end), 
    filterBank(n, Fs, &fd), 
    graphicEQ(n, Fs, &fd), 
    envelopes(n, {sampleRate}) 
{
        
}

VocoderProcessor::~VocoderProcessor() {

}

float VocoderProcessor::process_frame(float carrierInput, float modulatorInput) {
    filterBank.process_sample(modulatorInput);
    graphicEQ.process_sample(carrierInput);
    float result = 0;
    for (int i = 0; i < n; i++) {
        float gain = envelopes[i].process_sample(filterBank.getSampleFromFilter(i));
        result += gain * graphicEQ.getSampleFromFilter(i);
    }
    return result;
}