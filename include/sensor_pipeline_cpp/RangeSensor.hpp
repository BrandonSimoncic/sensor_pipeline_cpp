#include "Sensor.hpp"   // or however Sensor.hpp is included in this project

class RangeSensor : public Sensor {
public:
    SensorData readRaw() override;
    SensorData applyCalibration(SensorData data) override;
};