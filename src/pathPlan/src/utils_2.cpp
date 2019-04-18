#include "utils_2.h"
#include <Eigen/Dense>

#include <iostream>
#include <opencv2/opencv.hpp>
#define M_PI 3.14159265358979323846

using namespace std;

vector<float> dist_a_point_to_points(const Eigen::Vector2f &point1,
                                     const vector<Eigen::Vector2f> &points2) {
  vector<float> distances;
  distances.clear();
  if (points2.empty()) {
    return distances;
  }

  for (int i = 0; i < points2.size(); i++) {
    float distance = dist_a_point_to_point(point1, points2[i]);
    distances.push_back(distance);
  }
  return distances;
}

/*
 * call std::hypot to calculate L2-distance of two points.
 * see http://en.cppreference.com/w/cpp/numeric/math/hypot
 */
float dist_a_point_to_point(const Eigen::Vector2f &point1,
                            const Eigen::Vector2f &point2) {
  Eigen::Vector2f delta = point1 - point2;
  float distance = hypot(delta[0], delta[1]);

  return distance;
}

Eigen::Vector2f rotation_center(Eigen::Vector2f point, Eigen::Vector2f center,
                                float angle) {
  Eigen::Vector2f rotate;
  rotate[0] = (point[0] - center[0]) * cos(angle) -
              (point[1] - center[1]) * sin(angle) + center[0];
  rotate[1] = (point[0] - center[0]) * sin(angle) +
              (point[1] - center[1]) * cos(angle) + center[0];
  return rotate;
}

Eigen::Vector2f Body2Ground(Eigen::Vector2f point_in_body,
                            Eigen::Vector2f body_pos, float angle_g2b) {
  Eigen::Vector2f point_in_ground;
  Eigen::Matrix2f R;
  R << cos(angle_g2b), -sin(angle_g2b), sin(angle_g2b), cos(angle_g2b);
  point_in_ground = R * point_in_body;
  point_in_ground = point_in_ground + body_pos;
  return point_in_ground;
}

Eigen::Vector2f Ground2Body(Eigen::Vector2f point_in_ground,
                            Eigen::Vector2f body_pos, float angle_g2b) {
  Eigen::Vector2f point_in_body;
  Eigen::Matrix2f R;
  R << cos(angle_g2b), sin(angle_g2b), -sin(angle_g2b), cos(angle_g2b);
  point_in_body = point_in_ground - body_pos;
  point_in_body = R * point_in_body;
  return point_in_body;
}

cv::Mat imRotate(const cv::Mat source, float angle) {
  cv::Mat dst;
  // Special Cases
  if (std::fmod(angle, 360.0) == 0.0)
    dst = source;
  else {
    cv::Point2f center(source.cols / 2.0F - 0.5, source.rows / 2.0F - 0.5);
    cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
    // // determine bounding rectangle
    // cv::Rect bbox = cv::RotatedRect(center, source.size(),
    // angle).boundingRect();
    // // adjust transformation matrix
    // rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
    // rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;
    cv::warpAffine(source, dst, rot, source.size(), cv::INTER_LINEAR);
  }
  return dst;
}

void imBlur(const cv::Mat &src, cv::Mat &des) {
  // cv::Mat des(src.rows, src.cols, src.type());
  float sigma = 0;
  cv::Size ksize(51, 51);
  cv::GaussianBlur(src, des, ksize, sigma, sigma, cv::BORDER_REPLICATE);
  // return des;
}

cv::Mat occu2cost(cv::Mat occupancy_map) {
  cv::Mat cost_map(occupancy_map.rows, occupancy_map.cols, CV_32FC1);
  for (size_t i = 0; i < occupancy_map.rows; i++) {
    for (size_t j = 0; j < occupancy_map.cols; j++) {
      uchar uchar_data = occupancy_map.at<uchar>(i, j);
      float value = float(uchar_data) / 100.0;
      cost_map.at<float>(i, j) = value;
    }
  }
  return cost_map;
}

int CountLines(string filename) {
  ifstream ReadFile;
  int n = 0;
  string tmp;
  ReadFile.open(filename, ios::in);
  if (ReadFile.fail()) {
    return 0;
  } else {
    while (getline(ReadFile, tmp, '\n')) {
      n++;
    }
    ReadFile.close();
    return n;
  }
}

string ReadLine(string filename, int line) {
  int lines, i = 0;
  string temp;
  fstream file;
  file.open(filename, ios::in);
  lines = CountLines(filename);

  if (line <= 0) {
    return "Error 1";
  }
  if (file.fail()) {
    return "Error 2";
  }
  if (line > lines) {
    return "Error 3";
  }
  while (getline(file, temp) && i < line - 1) {
    i++;
  }
  file.close();
  return temp;
}

bool ReadFile2Vector(string filename, vector<Eigen::Vector2f> &path) {
  fstream file;
  file.open(filename, ios::in);
  if (file) {
    string str;
    while (getline(file, str, '\n')) {
      vector<float> data = str2Vector(str);
      Eigen::Vector2f Point(data[0], data[1]);
      path.push_back(Point);
    }
    return true;
  } else {
    path.clear();
    return false;
  }
}
int matchStr(string filename, string data) {
  int line = 1;
  string temp;
  fstream file;
  file.open(filename, ios::in);
  while (getline(file, temp)) {
    if (temp.find(data) != std::string::npos) {
      break;
    }
    line++;
  }
  file.close();
  return line;
}

vector<float> str2Vector(string line) {
  vector<float> temp_line;
  regex pat_regex("[-+]?[0-9]*\\.?[0-9]+");
  for (sregex_iterator it(line.begin(), line.end(), pat_regex), end_it;
       it != end_it; ++it) {
    temp_line.push_back(stof(it->str()));
  }
  return temp_line;
}

// void getData(string file_path, vector<Eigen::Vector2f> &global_path) {
//   int step = start_step;
//   cout << "step: " << step << endl;
//   /*1. set file dir*/

//   string state_dir = file_path + "state/state.txt";

//   /*2. acquire data from file*/
//   string str = ReadLine(state_dir, line);
//   cout << str << endl;
//   vector<float> state = str2Vector(str);
//   cur_pose << state[2], state[3], state[4];
//   cout << "cur_pose_x: " << state[2] << " cur_pose_y: " << state[3]
//        << " cur_pose_theta: " << state[4] << endl;
//   ReadFile2Vector(pathsearch_dir, global_path);
//   Eigen::Vector2f cur_vel;
//   cur_vel << state[5], state[6];

//   str = ReadLine(goal_dir, line);
//   vector<float> goal = str2Vector(str);
//   cur_goal << goal[3], goal[4];

// }

bool readFile2Vector(string filename, vector<Eigen::Vector2f> &path) {
  fstream file;
  file.open(filename, ios::in);
  if (file) {
    string str;
    while (getline(file, str, '\n')) {
      vector<float> data = str2Vector(str);
      Eigen::Vector2f Point(data[0], data[1]);
      path.push_back(Point);
    }
    return true;
  } else {
    path.clear();
    return false;
  }
}