#include <memory>
#include <string>
#include <stdexcept>

#include "Sensor.hpp"
#include "ImuSensor.hpp"
#include "RangeSensor.hpp"


class SensorFactory {
  public:
    static std::unique_ptr<Sensor> create(const std::string& type);

};