#include <vocoder/AudioFileWriter.hpp>
#include <miniaudio.h>
using namespace Vocoder;

AudioFileWriter::AudioFileWriter(std::string path, ma_uint32 sampleRate=44100, ma_encoding_format format=ma_encoding_format_wav) {
    // 0 should be native sample rate
    ma_encoder_config cfg = ma_encoder_config_init(format, ma_format_f32, 1, sampleRate);
    ma_encoder_init_file(path.c_str(), &cfg, &fileEncoder);
}

AudioFileWriter::~AudioFileWriter() {
    ma_encoder_uninit(&fileEncoder);
}

void AudioFileWriter::close() {
    ma_encoder_uninit(&fileEncoder);
}

ma_encoder& AudioFileWriter::getEncoderInstance() {
    return fileEncoder;
}

/*
 * Example:
 ```
 * AudioFileWriter a ("file.mp3");
 * float current_sample = 0.0f; 
 * while (a.get_sample(&current_sample)) {
 *      // ...
 * }
 * a.close();
 * ```
*/
bool AudioFileWriter::write_sample(float input) {
    ma_uint64 framesWritten = 0;
    return ma_encoder_write_pcm_frames(&fileEncoder, &input, 1, &framesWritten) == MA_SUCCESS;
}
