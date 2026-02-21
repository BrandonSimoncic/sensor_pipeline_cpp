#pragma once
#include "Processor.hpp"
#include "SensorData.hpp"

class LowPassFilter: public Processor {
    public:
        explicit LowPassFilter(double alpha);
        SensorData process(const SensorData& data) const override;
    private:
        double alpha_;
        mutable double last_value_ = 0.0;
};