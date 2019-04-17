#include <geometry_msgs/PointStamped.h>
#include <opencv2/opencv.hpp>
#include <ros/ros.h>
#include <tf/transform_listener.h>
// #include<opencv2/core/core.hpp>
// #include<opencv2/highgui/highgui.hpp>
// #include<opencv2/imgproc/imgproc.hpp>
#include "std_msgs/String.h"
#include <boost/thread.hpp>
#include <nav_msgs/OccupancyGrid.h>
#include <sstream>
// /**
//  * This tutorial demonstrates simple receipt of messages over the ROS system.
//  */
// void chatterCallback(const std_msgs::String::ConstPtr& msg)
// {
//   ROS_INFO("I heard: [%s]", msg->data.c_str());
// }

// int main(int argc, char **argv)
// {

//   ros::init(argc, argv, "listener");
//   ros::NodeHandle n;
//   ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
//   ros::spin();

//   return 0;
// }

void callback1(const nav_msgs::OccupancyGrid &map) {
  ROS_INFO("callback1 heard map : [%d]", map.info.width);




  ros::Rate loop_rate(1); // block chatterCallback2() 1Hz
  loop_rate.sleep();
}

void callback2(const geometry_msgs::PoseStamped &pose) {
  ROS_INFO("callback2 heard pose");
  // pose.pose.orientation
  ros::Rate loop_rate(1); // block chatterCallback2() 1Hz
  loop_rate.sleep();
}

int main(int argc, char **argv) {
  // Initiate ROS
  ros::init(argc, argv, "subscribe_two_topics");
  ros::NodeHandle n_;
  // use the latest 1 message
  ros::Subscriber sub_ = n_.subscribe("realtime_cost_map", 1, &callback1);
  ros::Subscriber sub2_ =
      n_.subscribe("segmatch/localization_avg", 1, &callback2);
  ros::Publisher cmd_vel_pub =
      n_.advertise<geometry_msgs::Twist>("/cmd_vel", 1);

  // ros::MultiThreadedSpinner spinner(3);  //多线程
  // ros::spin(spinner);
  ros::AsyncSpinner spinner(3); // Use 3 threads
  spinner.start();

  ros::Rate loop_rate(1);
  while (ros::ok()) {
    ROS_INFO("Ros ok in main");

    ros::spinOnce();
    loop_rate.sleep();
  }

  ros::waitForShutdown();
  ROS_INFO("ros finish");
  return 0;
}
