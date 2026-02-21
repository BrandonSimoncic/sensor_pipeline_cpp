#include "SensorFactory.hpp"


std::unique_ptr<Sensor> SensorFactory::create(const std::string& type) {
    if (type == "ImuSensor") {
      return std::make_unique<ImuSensor>();
    }
    if (type == "RangeSensor") {
      return std::make_unique<RangeSensor>();
    }
    throw std::invalid_argument("Unknown type");
  }
