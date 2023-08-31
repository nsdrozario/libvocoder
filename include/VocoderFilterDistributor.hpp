#pragma once
#include "FilterDistributor.hpp"

namespace Vocoder {
    class VocoderFilterDistributor : public FilterDistributor {
    public:
        VocoderFilterDistributor(unsigned long long sampleRate, int nMax, float startFreq, float endFreq);
        virtual ~VocoderFilterDistributor();
        virtual float getQ(int i) const;
        virtual float getCenterFreq(int i) const;
    };
}