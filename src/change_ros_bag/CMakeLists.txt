cmake_minimum_required(VERSION 2.8.3)
project(change_ros_bag)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Declare ROS messages and services

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(listener src/tf_and_scan.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener change_ros_bag_generate_messages_cpp)