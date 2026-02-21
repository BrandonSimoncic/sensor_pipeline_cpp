#pragma once
#include "Processor.hpp"


class ThresholdValidator : public Processor {
    public:
        ThresholdValidator(double min, double max);
        SensorData process(const SensorData& data) const override;

    private:
        double min_;
        double max_;
};