#ifndef _UTILS_2_H_
#define _UTILS_2_H_

#include <Eigen/Dense>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <regex>
#include <string>
#include <vector>

using namespace std;

enum class Read_File_Status {
  Read_OK = 0,
  File_Not_Exit = -1,
  File_Is_Empty = -2
};

enum class Tool_Status { Tool_Evaluate = 0, Tool_Plot };

enum PLOT_ERROR_CODE : uint64_t {
  No_Error = 0,
  Pose_Error = 1 << 0,
  Cur_Vel_Error = 1 << 1,
  Controller_Type_Error = 1 << 2,
  Best_Id_Error = 1 << 3,
  Goal_Error = 1 << 4,
  Tar_Vel_Error = 1 << 5,
  Nav_Mode_Error = 1 << 6,
  Obs_Map_Error = 1 << 7,
  Fisheye_Img_Error = 1 << 8
};

cv::Mat occu2cost(cv::Mat occupancy_map);
void imBlur(const cv::Mat &src, cv::Mat &des);
cv::Mat imRotate(const cv::Mat source, float angle);
// distance
float dist_a_point_to_point(const Eigen::Vector2f &point1,
                            const Eigen::Vector2f &point2);
vector<float>
dist_a_point_to_points(const Eigen::Vector2f &point1,
                       const std::vector<Eigen::Vector2f> &points2);
Eigen::Vector2f rotation_center(Eigen::Vector2f point, Eigen::Vector2f center,
                                float angle);
Eigen::Vector2f Ground2Body(Eigen::Vector2f point_in_ground,
                            Eigen::Vector2f body_pos, float angle_g2b);
Eigen::Vector2f Body2Ground(Eigen::Vector2f point_in_body,
                            Eigen::Vector2f body_pos, float angle_g2b);

bool ReadFile2Vector(string filename, vector<Eigen::Vector2f> &path);

int CountLines(string filename);
int matchStr(string filename, string data);
string ReadLine(string filename, int line);
vector<float> str2Vector(string line);

// Read_File_Status getStepInfo(const std::string txt_file_path, int &start_step,
//                              int &end_step);

 bool readFile2Vector(string filename, vector<Eigen::Vector2f> &path);

#endif //