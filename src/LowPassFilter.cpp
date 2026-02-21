#include "LowPassFilter.hpp"

LowPassFilter::LowPassFilter(double alpha) : alpha_(alpha) {}

SensorData LowPassFilter::process(const SensorData& data) const {
    last_value_ = alpha_ * data.value + (1.0 - alpha_) * last_value_;
    SensorData result = data;
    result.value = last_value_;
    return result;
}