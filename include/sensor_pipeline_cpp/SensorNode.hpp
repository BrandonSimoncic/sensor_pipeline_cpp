#pragma once
#include <vector>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "Sensor.hpp"
#include "ProcessingPipeline.hpp"
#include "SensorFactory.hpp"

class SensorNode : public rclcpp::Node {
public:
    SensorNode();

private:
    void timerCallback();

    std::vector<std::unique_ptr<Sensor>> sensors_;
    ProcessingPipeline pipeline_;
    rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};