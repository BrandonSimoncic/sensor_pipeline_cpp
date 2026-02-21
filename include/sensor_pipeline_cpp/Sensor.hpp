#pragma once
#include "rclcpp/rclcpp.hpp"
#include "SensorData.hpp"

class Sensor {
    public:
        virtual ~Sensor() = default;
        virtual SensorData update() {
            return applyCalibration(readRaw());
        };
        

    private:
        virtual SensorData readRaw() = 0;
        virtual SensorData applyCalibration(SensorData){
            return data;
        }
        SensorData data;

};


// // Shit to implement
// std::unique_ptr<Sensor> SensorFactory::create(const std::string& type);
// std::vector<std::unique_ptr<Processor>> processors_;
// SensorData process(const SensorData& data) const;
