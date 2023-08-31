#pragma once
#include "miniaudio.h"
#include <string>
namespace Vocoder {
    class AudioFileWriter {
    private:
        ma_encoder fileEncoder;
    public:
        AudioFileWriter(std::string path, ma_uint32 sampleRate=44100, ma_encoding_format format=ma_encoding_format_wav);
        ~AudioFileWriter();
        ma_encoder& getEncoderInstance();
        bool write_sample(float input);
        void close();
    };
}