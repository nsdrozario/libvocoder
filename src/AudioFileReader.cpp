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
