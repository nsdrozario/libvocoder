#pragma once
#include "miniaudio.h"

#define ENVELOPE_MAX_FREQ 20 

// https://www.mathworks.com/help/dsp/ug/envelope-detection.html
namespace Vocoder {
    class EnvelopeDetector {
    private:

        ma_lpf1 low_pass_filter;

    public:
        EnvelopeDetector(unsigned long long sample_rate);
        ~EnvelopeDetector();

        // Returns the resulting sample
        float process_sample(float input);

    }
}