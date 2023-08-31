#include <FilterBank.hpp>
using namespace Vocoder;

FilterBank::FilterBank(int num_filters, unsigned long long sample_rate, FilterDistributor *fd) : fd(fd), n(num_filters), Fs(sample_rate) {
    filters.resize(n);
    mostRecentSample.resize(n, 0.0f);
    for (int i = 0; i < n; i++) {
        ma_bpf2_config cfg = ma_bpf2_config_init(
            ma_format_f32,
            1,
            Fs,
            fd->getCenterFreq(i),
            fd->getQ(i)
        );
        ma_bpf2_init(&cfg, nullptr, &(filters[i]));
    }
}

FilterBank::~FilterBank() {

}

void FilterBank::process_sample(float in) {
    for (int i = 0; i < n; i++) {
        ma_bpf2_process_pcm_frames(&(filters[i]), &mostRecentSample[i], &in, 1);
    }
}

float FilterBank::getSampleFromFilter(int n) const {
    return mostRecentSample[n];
}