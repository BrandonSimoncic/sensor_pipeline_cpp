#include <memory>
#include "SensorNode.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SensorNode>());
  rclcpp::shutdown();
  return 0;
}