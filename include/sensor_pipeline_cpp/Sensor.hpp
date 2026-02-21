#pragma once
#include "rclcpp/rclcpp.hpp"
#include "SensorData.hpp"

class Sensor {
    public:
        virtual ~Sensor() = default;
        SensorData update() {
            return applyCalibration(readRaw());
        };
        

    private:
        virtual SensorData readRaw() = 0;
        virtual SensorData applyCalibration(SensorData data){
            return data;
        }
};


// // Shit to implement

// std::vector<std::unique_ptr<Processor>> processors_;
// SensorData process(const SensorData& data) const;
