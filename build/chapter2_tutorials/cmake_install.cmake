# Install script for directory: /home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/chapter2_tutorials" TYPE FILE FILES "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/devel/include/chapter2_tutorials/chapter2Config.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/chapter2_tutorials" TYPE FILE FILES "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/devel/lib/python2.7/dist-packages/chapter2_tutorials/__init__.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/devel/lib/python2.7/dist-packages/chapter2_tutorials/cfg")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/chapter2_tutorials" TYPE DIRECTORY FILES "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/devel/lib/python2.7/dist-packages/chapter2_tutorials/cfg")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/chapter2_tutorials/msg" TYPE FILE FILES "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/msg/chapter2_msg1.msg")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/chapter2_tutorials/srv" TYPE FILE FILES "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/srv/chapter2_srv1.srv")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/chapter2_tutorials/cmake" TYPE FILE FILES "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/build/chapter2_tutorials/catkin_generated/installspace/chapter2_tutorials-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/devel/include/chapter2_tutorials")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/devel/share/roseus/ros/chapter2_tutorials")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/devel/share/common-lisp/ros/chapter2_tutorials")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/devel/share/gennodejs/ros/chapter2_tutorials")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/devel/lib/python2.7/dist-packages/chapter2_tutorials")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/devel/lib/python2.7/dist-packages/chapter2_tutorials")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/build/chapter2_tutorials/catkin_generated/installspace/chapter2_tutorials.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/chapter2_tutorials/cmake" TYPE FILE FILES "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/build/chapter2_tutorials/catkin_generated/installspace/chapter2_tutorials-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/chapter2_tutorials/cmake" TYPE FILE FILES
    "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/build/chapter2_tutorials/catkin_generated/installspace/chapter2_tutorialsConfig.cmake"
    "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/build/chapter2_tutorials/catkin_generated/installspace/chapter2_tutorialsConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/chapter2_tutorials" TYPE FILE FILES "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/package.xml")
endif()

