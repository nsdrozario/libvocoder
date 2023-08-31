#pragma once
#include "FilterBank.hpp"
#include "EnvelopeDetector.hpp"
#include "VocoderFilterDistributor.hpp"
#include <vector>

namespace Vocoder {
    class VocoderProcessor {
    private:

        unsigned long long Fs;
        int n;
        float start;
        float end;

        VocoderFilterDistributor fd;
        FilterBank filterBank;
        FilterBank graphicEQ;

        std::vector<EnvelopeDetector> envelopes;
    
    public:
        
        VocoderProcessor(unsigned long long sampleRate, int nFilters, float start, float end);
        ~VocoderProcessor();

        float process_frame(float carrierInput, float modulatorInput);

    };
}