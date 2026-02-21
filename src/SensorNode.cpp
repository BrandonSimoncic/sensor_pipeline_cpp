#include "SensorNode.hpp"
#include "LowPassFilter.hpp"
#include "ThresholdValidator.hpp"

SensorNode::SensorNode() : Node("sensor_node") {
    // build sensors via factory - caller never touches concrete types
    sensors_.push_back(SensorFactory::create("ImuSensor"));
    sensors_.push_back(SensorFactory::create("RangeSensor"));

    // build pipeline - order matters
    pipeline_.addProcessor(std::make_unique<LowPassFilter>(0.1));
    pipeline_.addProcessor(std::make_unique<ThresholdValidator>(-100, 100));

    publisher_ = this->create_publisher<sensor_msgs::msg::Imu>("sensor_output", 10);

    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(100),
        std::bind(&SensorNode::timerCallback, this)
    );
}

void SensorNode::timerCallback() {
    for (const auto& sensor : sensors_) {
        SensorData raw = sensor->update();
        SensorData processed = pipeline_.run(raw);

        if (processed.valid) {
            auto msg = sensor_msgs::msg::Imu();
            msg.header.stamp = processed.timestamp;
            msg.linear_acceleration.x = processed.value;
            publisher_->publish(msg);
        }
    }
}

