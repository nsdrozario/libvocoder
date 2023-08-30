#pragma once
#include "miniaudio.h"
#include <vector>

namespace Vocoder {
    class FilterBank {
    private:
        
    public:
        FilterBank(int num_filters, size_t sample_rate);
        ~FilterBank();

        reset();

    }
}