
#include <EnvelopeDetector.hpp>

using namespace Vocoder;

EnvelopeDetector::EnvelopeDetector(unsigned long long sample_rate) {
    ma_lpf1_config cfg = ma_lpf1_config_init(
        ma_format_f32,
        1,
        sample_rate,
        ENVELOPE_MAX_FREQ
    );

    ma_lpf1_init(&cfg, nullptr, &low_pass_filter);
}

EnvelopeDetector::~EnvelopeDetector() {
}

float EnvelopeDetector::process_sample(float input) {
    float out = 0.0f;
    float in = input * input;
    ma_lpf1_process_pcm_frames(&low_pass_filter, &out, &in, 1);
    return out;
}