#ifndef _UTILS2_H_
#define _UTILS2_H_

#include <Eigen/Dense>
#include <vector>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <string>
#include <regex>


using namespace std;

cv::Mat occu2cost(cv::Mat occupancy_map);
void imBlur(const cv::Mat &src, cv::Mat & des);
cv::Mat imRotate(const cv::Mat source, float angle);
// distance
float dist_a_point_to_point(const Eigen::Vector2f &point1, const Eigen::Vector2f &point2);
vector<float> dist_a_point_to_points(const Eigen::Vector2f &point1, const std::vector<Eigen::Vector2f> &points2);
Eigen::Vector2f rotation_center(Eigen::Vector2f point, Eigen::Vector2f center, float angle);
Eigen::Vector2f Ground2Body(Eigen::Vector2f point_in_ground,Eigen::Vector2f body_pos, float angle_g2b);
Eigen::Vector2f Body2Ground(Eigen::Vector2f point_in_body,Eigen::Vector2f body_pos, float angle_g2b);

bool ReadFile2Vector(string filename, vector<Eigen::Vector2f> &path);

int CountLines(string filename);
int matchStr(string filename, string data);
string ReadLine(string filename,int line);
vector<float> str2Vector(string line);

#endif //