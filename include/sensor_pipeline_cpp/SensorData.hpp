#pragma once
#include <string>
#include "rclcpp/rclcpp.hpp"

struct SensorData {
    std::string sensor_id;
    double value;
    rclcpp::Time timestamp;
    bool valid = true;
};