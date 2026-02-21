#include "RangeSensor.hpp"
#include "SensorData.hpp"


SensorData RangeSensor::readRaw()  {
    SensorData new_data;
    new_data.sensor_id = "Range_NAMED";
    new_data.timestamp = rclcpp::Time();
    new_data.valid = true;
    new_data.value = 0;
    return new_data;
}
SensorData RangeSensor::applyCalibration(SensorData data)  {
    SensorData calibrated = data;
    calibrated.value = calibrated.value + 5;
    return calibrated;
}
