cmake_minimum_required(VERSION 3.5)

project(dienen_sim)

find_package(ament_cmake REQUIRED)
find_package(gazebo_ros REQUIRED)
find_package(rclcpp REQUIRED)

add_library(movement_plugin SHARED
  "src/dienen_sim/movement_plugin.cpp")

target_include_directories(movement_plugin PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

ament_target_dependencies(movement_plugin gazebo_ros rclcpp)

install(TARGETS movement_plugin
  DESTINATION "share/${PROJECT_NAME}/plugins")

install(DIRECTORY launch models worlds
  DESTINATION "share/${PROJECT_NAME}")

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
