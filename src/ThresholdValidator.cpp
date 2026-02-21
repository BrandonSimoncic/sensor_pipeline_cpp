#include "ThresholdValidator.hpp"

ThresholdValidator::ThresholdValidator( double min, double max)
: min_(min), max_(max) {}

SensorData ThresholdValidator::process(const SensorData& data) const {
    SensorData result = data;
    result.valid = (data.value >= min_ && data.value <= max_);
    return result;
}
