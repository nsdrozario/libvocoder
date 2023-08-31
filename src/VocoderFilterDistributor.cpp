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
#include <VocoderFilterDistributor.hpp>
#include <cmath>
using namespace Vocoder;

VocoderFilterDistributor::VocoderFilterDistributor(unsigned long long sampleRate, int nMax, float startFreq, float endFreq) : FilterDistributor(sampleRate, nMax, startFreq, endFreq) {

}

VocoderFilterDistributor::~VocoderFilterDistributor() {
    
}

float VocoderFilterDistributor::getCenterFreq(int i) const {
    // start * (base ^ n) = end
    // end/start = base ^ n
    // base = nth root of (end/start)
    // if not i+1 then we get a division by zero error
    float base = pow(end/start, 1.0f/n);
    return start * (pow(base, i)); 
}

float VocoderFilterDistributor::getQ(int i) const {
    // https://en.wikipedia.org/wiki/Constant-Q_transform;
    float bandwith = pow(pow(2, 1.0f/n), i) * start;
    return getCenterFreq(i)/bandwith;
}