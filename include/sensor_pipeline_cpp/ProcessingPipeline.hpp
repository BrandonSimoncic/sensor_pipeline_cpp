#pragma once
#include <vector>
#include <memory>
#include "Processor.hpp"
#include "SensorData.hpp"

class ProcessingPipeline {
public:
    void addProcessor(std::unique_ptr<Processor> processor);
    SensorData run(const SensorData& data) const;

private:
    std::vector<std::unique_ptr<Processor>> processors_;
};