#include "ImuSensor.hpp"
#include "SensorData.hpp"

SensorData ImuSensor::readRaw()  {
    SensorData new_data;
    new_data.sensor_id = "IMU_NAMED";
    new_data.timestamp = rclcpp::Time();
    new_data.valid = true;
    new_data.value = 0;
    return new_data;
}
SensorData ImuSensor::applyCalibration(SensorData data)  {
    SensorData calibrated = data;
    calibrated.value = calibrated.value + 5;
    return calibrated;
}
