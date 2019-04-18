cmake_minimum_required(VERSION 2.8.3)

project(chapter5_tutorials)

SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  tf
)

catkin_package()

# include_directories(
#   ${catkin_INCLUDE_DIRS}
# )
link_directories(
  lib ${catkin_LIB_DIRS} 
)
include_directories(
  include  ${catkin_INCLUDE_DIRS}  
)



add_executable(tf_broadcast src/tf_broadcaster.cpp)
target_link_libraries(tf_broadcast ${catkin_LIBRARIES})

add_executable(tf_listener src/tf_listener.cpp)
target_link_libraries(tf_listener ${catkin_LIBRARIES})

add_executable(laser src/laser.cpp)
target_link_libraries(laser ${catkin_LIBRARIES})

add_executable(odometry src/odometry.cpp)
target_link_libraries(odometry ${catkin_LIBRARIES})

add_executable(base_controller src/base_controller.cpp)
target_link_libraries(base_controller ${catkin_LIBRARIES})


add_executable(path_plan_sim src/path_plan_sim.cpp)
target_link_libraries(path_plan_sim ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})


target_link_libraries(path_plan_sim 	${catkin_LIBRARIES}	pathplan)