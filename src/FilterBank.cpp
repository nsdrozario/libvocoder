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
#include <FilterBank.hpp>
using namespace Vocoder;

FilterBank::FilterBank(int num_filters, unsigned long long sample_rate, FilterDistributor *fd) : fd(fd), n(num_filters), Fs(sample_rate) {
    filters.resize(n);
    mostRecentSample.resize(n, 0.0f);
    for (int i = 0; i < n; i++) {
        ma_bpf2_config cfg = ma_bpf2_config_init(
            ma_format_f32,
            1,
            Fs,
            fd->getCenterFreq(i),
            fd->getQ(i)
        );
        ma_bpf2_init(&cfg, nullptr, &(filters[i]));
    }
}

FilterBank::~FilterBank() {

}

void FilterBank::process_sample(float in) {
    for (int i = 0; i < n; i++) {
        ma_bpf2_process_pcm_frames(&(filters[i]), &mostRecentSample[i], &in, 1);
    }
}

float FilterBank::getSampleFromFilter(int n) const {
    return mostRecentSample[n];
}