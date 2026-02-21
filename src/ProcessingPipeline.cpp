#include "ProcessingPipeline.hpp"

void ProcessingPipeline::addProcessor(std::unique_ptr<Processor> processor) {
    processors_.push_back(std::move(processor));
}

SensorData ProcessingPipeline::run(const SensorData& data) const {
    SensorData current = data;
    for (const auto& processor : processors_) {
        current = processor->process(current);
    }
    return current;
}