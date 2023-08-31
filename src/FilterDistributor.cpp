#include <FilterDistributor.hpp>
#include <tuple>

using namespace Vocoder;

FilterDistributor::FilterDistributor(
    unsigned long long sample_rate,
    int nMax, 
    float startFreq, 
    float endFreq
) : Fs(sample_rate), n(nMax), start(startFreq), end(endFreq) {

}

std::tuple<float, float> FilterDistributor::operator () (int i) const {
    return std::tuple<float, float>(getCenterFreq(i), getQ(i));
} 