#include <VocoderFilterDistributor.hpp>
#include <cmath>
using namespace Vocoder;

VocoderFilterDistributor::VocoderFilterDistributor(unsigned long long sampleRate, int nMax, float startFreq, float endFreq) : FilterDistributor(sampleRate, nMax, startFreq, endFreq) {

}

float VocoderFilterDistributor::getCenterFreq(int i) const {
    // start * (base ^ n) = end
    // end/start = base ^ n
    // base = nth root of (end/start)
    return start * pow(end/start, 1.0f/i); 
}

float VocoderFilterDistributor::getQ(int i) const {
    return 4;
}