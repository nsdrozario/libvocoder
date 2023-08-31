#pragma once
#include "miniaudio.h"
#include <vector>
#include "FilterDistributor.hpp"

namespace Vocoder {
    class FilterBank {
    private:
        std::vector<ma_bpf2> filters;
        std::vector<float> mostRecentSample;

        FilterDistributor *fd;
        unsigned long long Fs;
        int n;
    public:
        FilterBank(int num_filters, unsigned long long sampleRate, FilterDistributor *fd);
        ~FilterBank();

        void process_sample(float in);
        float getSampleFromFilter(int n) const;
    };
}