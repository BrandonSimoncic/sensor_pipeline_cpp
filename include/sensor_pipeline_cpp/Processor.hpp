#pragma once
#include "SensorData.hpp"

class Processor {
public:
    virtual ~Processor() = default;
    virtual SensorData process(const SensorData& data) const = 0;
};