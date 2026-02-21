#include "Sensor.hpp"   // or however Sensor.hpp is included in this project

class ImuSensor : public Sensor {
private:
    SensorData readRaw() override;
    SensorData applyCalibration(SensorData data) override;
};