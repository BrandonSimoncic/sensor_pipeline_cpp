cmake_minimum_required(VERSION 3.20)
project(sensor_pipeline_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)


# executable that uses SensorNode, ImuSensor, Sensor, SensorFactory
add_executable(sensor_node
  src/SensorNode.cpp
  src/ImuSensor.cpp
  src/RangeSensor.cpp
  src/ProcessingPipeline.cpp
  src/ThresholdValidator.cpp
  src/LowPassFilter.cpp
  src/SensorFactory.cpp
  src/main.cpp
)
target_include_directories(sensor_node PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include/sensor_pipeline_cpp
)
target_link_libraries(sensor_node PUBLIC
      ${sensor_msgs_TARGETS}
      ${std_msgs_TARGETS}
      rclcpp::rclcpp
      sensor_msgs::sensor_msgs_library
    )

# install
install(TARGETS sensor_node
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
