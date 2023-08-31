#pragma once
#include "FilterBank.hpp"
#include "EnvelopeDetector.hpp"
#include "VocoderFilterDistributor.hpp"
#include <vector>

namespace Vocoder {
    class VocoderProcessor {
    private:
        
        FilterBank filterBank;
        FilterBank graphicEQ;

        std::vector<EnvelopeDetector> envelopes;
        VocoderFilterDistributor fd;

        unsigned long long Fs;
        int n;
        float start;
        float end;

    public:
        
        VocoderProcessor(unsigned long long sampleRate, int nFilters, float start, float end);
        ~VocoderProcessor();

        float process_frame(float carrierInput, float modulatorInput);

    };
}