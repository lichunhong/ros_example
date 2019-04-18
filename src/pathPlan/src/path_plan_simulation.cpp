#include "Eigen/Dense"
#include "std_msgs/String.h"
#include <boost/thread.hpp>
#include <geometry_msgs/PointStamped.h>
#include <nav_msgs/OccupancyGrid.h>
#include <opencv2/core/core.hpp>
// #include <opencv2/highgui/highgui.hpp>
// #include <opencv2/imgproc/imgproc.hpp>
// #include <opencv2/opencv.hpp>
#include <ros/ros.h>
#include <sstream>
#include <tf/transform_listener.h>
// can not include header files in include ???
#include "CtrlCmd.h"
#include "NinebotAlgoMP.h"
#include "PlannerImpl.h"
#include "PlannerInterface.h"
// #include "PlannerParam.h"
#include "utils_2.h"
// #include "DebugUtils.h"

using namespace ninebot_algo::motion_planner;
using namespace ninebot_algo;
using namespace std;

// cv::Mat draw_grid(const nav_msgs::OccupancyGrid &grid);
const std::string img_path = "./1111.png";
const std::string rotate_img_path = "./2222.png";
const std::string ref_traj_path = "./src/pathPlan/bag/refTraj.txt";
// %time,field.header.seq,field.header.stamp,field.header.frame_id,field.pose.position.x,field.pose.position.y,field.pose.position.z,field.pose.orientation.x,field.pose.orientation.y,field.pose.orientation.z,field.pose.orientation.w

vector<Eigen::Vector2f> ref_path;
cv::Mat obstacle_map;
int int first_step_seq, cur_step_seq;
float last_theta, cur_theta; //上次车辆转角 和 当前转角  callback2调用
//上次车的位置 和 当前车的位置  callback2调用
float last_pos_x, cur_pos_x, last_pos_y, cur_pos_y;

bool readFile2Vector(std::string filename, vector<Eigen::Vector2f> &path) {
  fstream file;
  file.open(filename, ios::in);
  bool first_line_flag = true;

  cout << "readFile2Vector  in" << endl;
  if (file) {
    string str;
    while (getline(file, str, '\n')) {
      vector<float> data = str2Vector(str);
      if (first_line_flag) {
        first_step_seq  = data[1];
        first_line_flag = false;
      }
      // put xy in vector
      Eigen::Vector2f Point(data[4], data[5]);
      // cout << "data 4: " << data[4] << " data5 " << data[5] << endl;
      path.push_back(Point);
    }
    return true;
  } else {
    path.clear();
    return false;
  }
}

// function to draw the occupancy grid to an image
cv::Mat draw_grid(const nav_msgs::OccupancyGrid &grid) {
  cv::Mat map_img = cv::Mat::zeros(60, 60, CV_8UC1);
  for (int i = 220; i < 280; i++) {
    uchar *rowi = map_img.ptr<uchar>(i - 220);
    for (int j = 220; j < 280; j++) {
      rowi[j - 220] = grid.data[i + j * 500];
      // map_img.at<double>(i,j) = 0;
    }
    cv::imwrite(img_path, map_img);
  }
  return map_img;
}
// //图像矩阵旋转180°
// void rotateImage(cv::Mat &src, cv::Mat &dst) {
//   cv::Size src_sz = src.size();
//   cv::Size dst_sz(src_sz.height, src_sz.width);
//   dst = cv::Mat::zeros(dst_sz, CV_8UC1);
//   int len = std::max(src.cols, src.rows);
//   //指定旋转中心
//   cv::Point2f center(len / 2., len / 2.);
//   //获取旋转矩阵（2x3矩阵）
//   cv::Mat rot_mat = cv::getRotationMatrix2D(center, 180, 1.0);
//   //根据旋转矩阵进行仿射变换
//   cv::warpAffine(src, dst, rot_mat, dst_sz);
//   cv::imwrite(rotate_img_path, dst);
//   ROS_INFO("draw rotate_img");
// }

void callback1(const nav_msgs::OccupancyGrid &map) {
  ROS_INFO("callback1 heard map : [%d]", map.info.width);

  cv::Mat origin_obstacle_map = draw_grid(map);
  // rotateImage(origin_obstacle_map, obstacle_map);
  obstacle_map = imRotate(origin_obstacle_map, 90);
  ros::Rate loop_rate(1); // block chatterCallback2() 1Hz
  loop_rate.sleep();
}

void callback2(const geometry_msgs::PoseStamped &pose) {
  ROS_INFO("callback2 heard pose");
  // pose.pose.orientation
  cur_step_seq = pose.header.seq;
  //  orientation to ruler
  // tf::Matrix3x3 mat(tf::Quaternion(data[7], data[8], data[9], data[10]));
  tf::Matrix3x3 mat(
      tf::Quaternion(pose.pose.orientation.x, pose.pose.orientation.y,
                     pose.pose.orientation.z, pose.pose.orientation.w));
  double yaw, pitch, roll;
  mat.getEulerYPR(yaw, pitch, roll);
  cout << "yaw: " << yaw << " pitch " << pitch << "roll " << roll << endl;

  last_theta = cur_theta;
  cur_theta = pitch;

  last_pos_x = cur_pos_x;
  cur_pos_x = pose.pose.position.x;

  last_pos_y = cur_pos_y;
  cur_pos_y = pose.pose.position.y;

  ros::Rate loop_rate(1); // block chatterCallback2() 1Hz
  loop_rate.sleep();
}

void pathPlan() {
  ninebot_algo::motion_planner::AprIndoorPlanner *m_p_apr_indoor_planner;
  ninebot_algo::motion_planner::LocalPlanDwa *m_p_apr_local_planner;
}

int main(int argc, char **argv) {
  // Initiate ROS
  ros::init(argc, argv, "path_plan_simulation");
  ros::NodeHandle n_;

  // read ref trajectry
  bool state = readFile2Vector(ref_traj_path, ref_path);
  cout << "state = " << state << endl;
  ROS_INFO("ref_path size = [%d] ", (int)ref_path.size());

  // use the latest 1 message
  ros::Subscriber sub_ = n_.subscribe("/realtime_cost_map", 1, &callback1);
  ros::Subscriber sub2_ =
      n_.subscribe("/segmatch/localization_avg", 1, &callback2);
  ros::Publisher cmd_vel_pub =
      n_.advertise<geometry_msgs::PoseStamped>("/ref_traj", 1);

  // ros::MultiThreadedSpinner spinner(3);  //多线程
  // ros::spin(spinner);
  ros::AsyncSpinner spinner(3); // Use 3 threads
  spinner.start();

  ros::Rate loop_rate(1);
  while (ros::ok()) {
    ROS_INFO("Ros ok in main");

    pathPlan();

    ros::spinOnce();
    loop_rate.sleep();
  }

  ros::waitForShutdown();
  ROS_INFO("ros finish");
  return 0;
}
