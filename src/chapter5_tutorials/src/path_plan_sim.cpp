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


#include "CtrlCmd.h"
#include "NinebotAlgoMP.h"
#include "PlannerImpl.h"
#include "PlannerInterface.h"
// #include "PlannerParam.h"
// can not include header files in include ???
// #include "chapter5_tutorials/CtrlCmd.h"
// #include "chapter5_tutorials/NinebotAlgoMP.h"
using namespace ninebot_algo::motion_planner;
using namespace ninebot_algo;
using namespace std;


// cv::Mat draw_grid(const nav_msgs::OccupancyGrid &grid);
const std::string img_path = "./1111.png";
const std::string rotate_img_path = "./2222.png";
cv::Mat obstacle_map;

// function to draw the occupancy grid to an image
cv::Mat draw_grid(const nav_msgs::OccupancyGrid &grid) {
  cv::Mat map_img = cv::Mat::zeros(120, 120, CV_8UC1);
  for (int i = 190; i < 310; i++) {
    uchar *rowi = map_img.ptr<uchar>(i - 190);
    for (int j = 190; j < 310; j++) {
      rowi[j - 190] = grid.data[i + j * 500];
      // map_img.at<double>(i,j) = 0;
    }
    cv::imwrite(img_path, map_img);
  }
  return map_img;
}
//图像矩阵旋转180°
void rotateImage(cv::Mat &src, cv::Mat &dst) {
  cv::Size src_sz = src.size();
  cv::Size dst_sz(src_sz.height, src_sz.width);
  dst = cv::Mat::zeros(dst_sz, CV_8UC1);
  int len = std::max(src.cols, src.rows);
  //指定旋转中心
  cv::Point2f center(len / 2., len / 2.);
  //获取旋转矩阵（2x3矩阵）
  cv::Mat rot_mat = cv::getRotationMatrix2D(center, 180, 1.0);
  //根据旋转矩阵进行仿射变换
  cv::warpAffine(src, dst, rot_mat, dst_sz);
  cv::imwrite(rotate_img_path, dst);
  ROS_INFO("draw rotate_img");
}

void callback1(const nav_msgs::OccupancyGrid &map) {
  ROS_INFO("callback1 heard map : [%d]", map.info.width);

  cv::Mat origin_obstacle_map = draw_grid(map);
  rotateImage(origin_obstacle_map, obstacle_map);
  ros::Rate loop_rate(1); // block chatterCallback2() 1Hz
  loop_rate.sleep();
}

void callback2(const geometry_msgs::PoseStamped &pose) {
  ROS_INFO("callback2 heard pose");
  // pose.pose.orientation
  ros::Rate loop_rate(1); // block chatterCallback2() 1Hz
  loop_rate.sleep();
}

// void pathPlan() {
//   std::vector<Eigen::Vector2f> m_ref_trajectory;
//   ModelBasedPlanner *planner = nullptr;
//   bool m_is_planning_forward = true;
//   int controller_type = 1;
//   int type_robot = 2;
//   if (planner == nullptr) {
//     if (type_robot<Cylinder | type_robot> GX_EVT4_5) {
//       type_robot = GX;
//     }
//     planner = new ModelBasedPlanner(
//         m_ref_trajectory, true,
//         ninebot_algo::motion_planner::TypeRobot(type_robot));
//     setPlannerParam(planner);
//     planner->dwaTrajInit();
//   }
// }


void pathPlan(){
  ninebot_algo::motion_planner::AprIndoorPlanner *m_p_apr_indoor_planner;
  ninebot_algo::motion_planner::LocalPlanDwa *m_p_apr_local_planner;





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

    pathPlan();

    ros::spinOnce();
    loop_rate.sleep();
  }

  ros::waitForShutdown();
  ROS_INFO("ros finish");
  return 0;
}
