#pragma once
#include "miniaudio.h"
#include <string>
namespace Vocoder {
    class AudioFileReader {
    private:
        ma_decoder fileDecoder;
    public:
        AudioFileReader(std::string path);
        ~AudioFileReader();
        ma_decoder& getDecoderInstance();
        bool get_sample(float *output);
        void close();
    };
}