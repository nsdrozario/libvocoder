#include <VocoderProcessor.hpp>
using namespace Vocoder;

VocoderProcessor::VocoderProcessor(unsigned long long sampleRate, int nFilters, float start, float end) : 
    Fs(sampleRate), 
    n(nFilters), 
    start(start), 
    end(end), 
    fd(sampleRate, nFilters, start, end), 
    filterBank(n, Fs, &fd), 
    graphicEQ(n, Fs, &fd), 
    envelopes(n) 
{
        
}

VocoderProcessor::~VocoderProcessor() {

}

float VocoderProcessor::process_frame(float carrierInput, float modulatorInput) {
    filterBank.process_sample(modulatorInput);
    graphicEQ.process_sample(carrierInput);
    float result = 0;
    for (int i = 0; i < n; i++) {
        float gain = envelopes[i].process_sample(filterBank.getSampleFromFilter(i));
        result += gain * graphicEQ.getSampleFromFilter(i);
    }
    return result;
}