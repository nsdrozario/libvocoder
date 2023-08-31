#pragma once 
#include <tuple>
namespace Vocoder {
    class FilterDistributor {
    protected:
        unsigned long long Fs;
        int n;
        float start;
        float end;
    public:
        FilterDistributor(unsigned long long sampleRate, int nMax, float startFreq, float endFreq);
        virtual ~FilterDistributor() {}
        virtual float getQ(int i) const = 0;
        virtual float getCenterFreq(int i) const = 0;
    };
}