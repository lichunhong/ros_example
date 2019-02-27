# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "chapter2_tutorials: 1 messages, 1 services")

set(MSG_I_FLAGS "-Ichapter2_tutorials:/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genjava REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(chapter2_tutorials_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/msg/chapter2_msg1.msg" NAME_WE)
add_custom_target(_chapter2_tutorials_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "chapter2_tutorials" "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/msg/chapter2_msg1.msg" ""
)

get_filename_component(_filename "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/srv/chapter2_srv1.srv" NAME_WE)
add_custom_target(_chapter2_tutorials_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "chapter2_tutorials" "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/srv/chapter2_srv1.srv" ""
)

#
#  langs = gencpp;geneus;genjava;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(chapter2_tutorials
  "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/msg/chapter2_msg1.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/chapter2_tutorials
)

### Generating Services
_generate_srv_cpp(chapter2_tutorials
  "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/srv/chapter2_srv1.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/chapter2_tutorials
)

### Generating Module File
_generate_module_cpp(chapter2_tutorials
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/chapter2_tutorials
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(chapter2_tutorials_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(chapter2_tutorials_generate_messages chapter2_tutorials_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/msg/chapter2_msg1.msg" NAME_WE)
add_dependencies(chapter2_tutorials_generate_messages_cpp _chapter2_tutorials_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/srv/chapter2_srv1.srv" NAME_WE)
add_dependencies(chapter2_tutorials_generate_messages_cpp _chapter2_tutorials_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(chapter2_tutorials_gencpp)
add_dependencies(chapter2_tutorials_gencpp chapter2_tutorials_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS chapter2_tutorials_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(chapter2_tutorials
  "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/msg/chapter2_msg1.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/chapter2_tutorials
)

### Generating Services
_generate_srv_eus(chapter2_tutorials
  "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/srv/chapter2_srv1.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/chapter2_tutorials
)

### Generating Module File
_generate_module_eus(chapter2_tutorials
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/chapter2_tutorials
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(chapter2_tutorials_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(chapter2_tutorials_generate_messages chapter2_tutorials_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/msg/chapter2_msg1.msg" NAME_WE)
add_dependencies(chapter2_tutorials_generate_messages_eus _chapter2_tutorials_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/srv/chapter2_srv1.srv" NAME_WE)
add_dependencies(chapter2_tutorials_generate_messages_eus _chapter2_tutorials_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(chapter2_tutorials_geneus)
add_dependencies(chapter2_tutorials_geneus chapter2_tutorials_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS chapter2_tutorials_generate_messages_eus)

### Section generating for lang: genjava
### Generating Messages
_generate_msg_java(chapter2_tutorials
  "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/msg/chapter2_msg1.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genjava_INSTALL_DIR}/chapter2_tutorials
)

### Generating Services
_generate_srv_java(chapter2_tutorials
  "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/srv/chapter2_srv1.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genjava_INSTALL_DIR}/chapter2_tutorials
)

### Generating Module File
_generate_module_java(chapter2_tutorials
  ${CATKIN_DEVEL_PREFIX}/${genjava_INSTALL_DIR}/chapter2_tutorials
  "${ALL_GEN_OUTPUT_FILES_java}"
)

add_custom_target(chapter2_tutorials_generate_messages_java
  DEPENDS ${ALL_GEN_OUTPUT_FILES_java}
)
add_dependencies(chapter2_tutorials_generate_messages chapter2_tutorials_generate_messages_java)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/msg/chapter2_msg1.msg" NAME_WE)
add_dependencies(chapter2_tutorials_generate_messages_java _chapter2_tutorials_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/srv/chapter2_srv1.srv" NAME_WE)
add_dependencies(chapter2_tutorials_generate_messages_java _chapter2_tutorials_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(chapter2_tutorials_genjava)
add_dependencies(chapter2_tutorials_genjava chapter2_tutorials_generate_messages_java)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS chapter2_tutorials_generate_messages_java)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(chapter2_tutorials
  "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/msg/chapter2_msg1.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/chapter2_tutorials
)

### Generating Services
_generate_srv_lisp(chapter2_tutorials
  "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/srv/chapter2_srv1.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/chapter2_tutorials
)

### Generating Module File
_generate_module_lisp(chapter2_tutorials
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/chapter2_tutorials
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(chapter2_tutorials_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(chapter2_tutorials_generate_messages chapter2_tutorials_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/msg/chapter2_msg1.msg" NAME_WE)
add_dependencies(chapter2_tutorials_generate_messages_lisp _chapter2_tutorials_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/srv/chapter2_srv1.srv" NAME_WE)
add_dependencies(chapter2_tutorials_generate_messages_lisp _chapter2_tutorials_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(chapter2_tutorials_genlisp)
add_dependencies(chapter2_tutorials_genlisp chapter2_tutorials_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS chapter2_tutorials_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(chapter2_tutorials
  "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/msg/chapter2_msg1.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/chapter2_tutorials
)

### Generating Services
_generate_srv_nodejs(chapter2_tutorials
  "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/srv/chapter2_srv1.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/chapter2_tutorials
)

### Generating Module File
_generate_module_nodejs(chapter2_tutorials
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/chapter2_tutorials
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(chapter2_tutorials_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(chapter2_tutorials_generate_messages chapter2_tutorials_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/msg/chapter2_msg1.msg" NAME_WE)
add_dependencies(chapter2_tutorials_generate_messages_nodejs _chapter2_tutorials_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/srv/chapter2_srv1.srv" NAME_WE)
add_dependencies(chapter2_tutorials_generate_messages_nodejs _chapter2_tutorials_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(chapter2_tutorials_gennodejs)
add_dependencies(chapter2_tutorials_gennodejs chapter2_tutorials_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS chapter2_tutorials_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(chapter2_tutorials
  "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/msg/chapter2_msg1.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/chapter2_tutorials
)

### Generating Services
_generate_srv_py(chapter2_tutorials
  "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/srv/chapter2_srv1.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/chapter2_tutorials
)

### Generating Module File
_generate_module_py(chapter2_tutorials
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/chapter2_tutorials
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(chapter2_tutorials_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(chapter2_tutorials_generate_messages chapter2_tutorials_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/msg/chapter2_msg1.msg" NAME_WE)
add_dependencies(chapter2_tutorials_generate_messages_py _chapter2_tutorials_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lichunhong/Documents/src/effective_robotics_programming_with_ros-master/catkin_ws/src/chapter2_tutorials/srv/chapter2_srv1.srv" NAME_WE)
add_dependencies(chapter2_tutorials_generate_messages_py _chapter2_tutorials_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(chapter2_tutorials_genpy)
add_dependencies(chapter2_tutorials_genpy chapter2_tutorials_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS chapter2_tutorials_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/chapter2_tutorials)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/chapter2_tutorials
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(chapter2_tutorials_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/chapter2_tutorials)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/chapter2_tutorials
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(chapter2_tutorials_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genjava_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genjava_INSTALL_DIR}/chapter2_tutorials)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genjava_INSTALL_DIR}/chapter2_tutorials
    DESTINATION ${genjava_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_java)
  add_dependencies(chapter2_tutorials_generate_messages_java std_msgs_generate_messages_java)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/chapter2_tutorials)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/chapter2_tutorials
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(chapter2_tutorials_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/chapter2_tutorials)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/chapter2_tutorials
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(chapter2_tutorials_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/chapter2_tutorials)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/chapter2_tutorials\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/chapter2_tutorials
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(chapter2_tutorials_generate_messages_py std_msgs_generate_messages_py)
endif()
