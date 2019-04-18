cmake_minimum_required(VERSION 2.8.3)

project(path_plan)

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


link_directories(
  lib ${catkin_LIB_DIRS} 
)
include_directories(
  include  ${catkin_INCLUDE_DIRS}  
)

# # a executable doc mast have a main() function 
# add_executable(utils_2 src/utils_2.cpp)
# target_link_libraries(utils_2 ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})


add_executable(path_plan_simulation src/path_plan_simulation.cpp)
target_link_libraries(path_plan_simulation ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})


target_link_libraries(path_plan_simulation 	${catkin_LIBRARIES}	pathplan)
