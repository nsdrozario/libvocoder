#include <vocoder/VocoderProcessor.hpp>
#include <vocoder/AudioFileReader.hpp>
#include <vocoder/AudioFileWriter.hpp>
#include <cmath>
using namespace Vocoder;

int main(int argc, char *argv[]) {

    if (argc < 2) { exit(0); }

    AudioFileReader a (argv[1]);
    ma_decoder& decoder = a.getDecoderInstance();
    AudioFileWriter w ("out.mp3", decoder.outputSampleRate, ma_encoding_format_wav);
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
