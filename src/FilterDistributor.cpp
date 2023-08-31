#include <FilterDistributor.hpp>
#include <tuple>

using namespace Vocoder;

FilterDistributor::FilterDistributor(
    unsigned long long sampleRate,
    int nMax, 
    float startFreq, 
    float endFreq
) : Fs(sampleRate), n(nMax), start(startFreq), end(endFreq) {

}

std::tuple<float, float> FilterDistributor::operator () (int i) const {
    return std::tuple<float, float>(getCenterFreq(i), getQ(i));
} 