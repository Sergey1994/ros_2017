cmake_minimum_required(VERSION 2.8.3)
project(lab2)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
roscpp
std_msgs
message_generation
)

add_service_files(
FILES
AddTwoInts.srv
Repair.srv
)

generate_messages(
DEPENDENCIES
std_msgs
)

## Declare a catkin package
catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

## Build talker and listener
add_executable(doctor src/doctor.cpp)
target_link_libraries(doctor ${catkin_LIBRARIES})
add_dependencies(doctor lab2_gencpp)

add_executable(sick src/sick.cpp)
target_link_libraries(sick ${catkin_LIBRARIES})
add_dependencies(sick lab2_gencpp)
