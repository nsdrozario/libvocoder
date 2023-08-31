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
#include <vocoder/VocoderProcessor.hpp>
#include <vocoder/AudioFileReader.hpp>
#include <vocoder/AudioFileWriter.hpp>
#include <cmath>
#include <ctime>

using namespace Vocoder;

int main(int argc, char *argv[]) {

    if (argc < 2) { exit(0); }

    srand(time(nullptr));

    AudioFileReader a (argv[1]);
    ma_decoder& decoder = a.getDecoderInstance();
    AudioFileWriter w ("out.wav", decoder.outputSampleRate, ma_encoding_format_wav);
    VocoderProcessor proc (decoder.outputSampleRate, 30, 50, 8000);

    float sample = 0.0f;
    while (a.get_sample(&sample)) {
        float random = (( (float) rand() / RAND_MAX ) - 0.5f) * 2.0f;
        float out = proc.process_frame(random, sample);
        w.write_sample(out);
    }

    a.close();
    w.close();

    return 0;
}
