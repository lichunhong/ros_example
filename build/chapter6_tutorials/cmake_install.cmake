# Install script for directory: /home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter6_tutorials

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/build/chapter6_tutorials/catkin_generated/installspace/chapter6_tutorials.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/chapter6_tutorials/cmake" TYPE FILE FILES
    "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/build/chapter6_tutorials/catkin_generated/installspace/chapter6_tutorialsConfig.cmake"
    "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/build/chapter6_tutorials/catkin_generated/installspace/chapter6_tutorialsConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/chapter6_tutorials" TYPE FILE FILES "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter6_tutorials/package.xml")
endif()

