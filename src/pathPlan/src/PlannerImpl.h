#ifndef MOTIONPLANNER_MOTIONPLANNER_H
#define MOTIONPLANNER_MOTIONPLANNER_H


#include "PlannerInterface.h"

#include <cv.hpp>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>

namespace ninebot_algo{ namespace motion_planner {


    class ObstacleGridMap : public IObstacleMap {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        ObstacleGridMap(float pix_scale=0.05f);
        ObstacleGridMap(cv::Mat &map, float pix_scale=0.05f);
        ~ObstacleGridMap() override {};

        static void fromPng(std::string file_path);
        int crop(PoseSE2 center, Eigen::Vector2f range, IObstacleMap& output) override ;
        void setMap(cv::Mat map);

        cv::Mat map;
        float pix_scale;
    };


    class LocalPlanDwa;
    class PathPlanThetaStar;
    class CtrlCmd;
    class AprIndoorPlanner : public IMotionPlanner {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        /**
         * @param path_planner : "none"/"theta_star"
         * @param local_planner : "dwa"
         * @param traj_tracker : "none"
         * @param robot_type : "GX"/"GX_EVT4"
         */
        AprIndoorPlanner(
                std::string path_planner = "none",
                std::string local_planner = "dwa",
                std::string traj_tracker = "none",
                TypeRobot robot_type = GX);

        ~AprIndoorPlanner();

//        void setRobotProfile(IRobotProfile &profile) override;

        void setReferenceTrajectory(Trajectory &traj) override;

        void setReferenceTrajectory(std::vector<Eigen::Vector2f> traj);

        int makePlan(PoseSE2 pose, Eigen::Vector2f speed,
                     IObstacleMap &static_map) override;

        Trajectory getOptimalTrajectory() override;

        Eigen::Vector2f getOptimalControlCmd() override;

//        m_path_planner target
        PoseSE2 getCurrentTarget() override;

        void setPlannerMode();

        LocalPlanDwa* getLocalPlannerInstance();

        PathPlanThetaStar* getPathPlannerInstance();

//        m_path_planner
        std::pair<int, Eigen::Vector2f> getCurGoal();

        std::vector<Eigen::Vector2f> getPathPlannerTraj();

        std::vector<int> curveGoalRegion(const std::vector<Eigen::Vector2f>& traj);

        std::vector<int> getCurveGoalRegion();

        void updateMaxCurveVelocity(int cur_goal_id);

        void updateMaxCloudVelocity();

        void updateMaxTrajVelocity();

        void updateMaxCmdVelocity();

//        default param: 1. m_max_curve_vel = 1.2; m_min_curve_vel = 0.5; m_vel_slow_step = 0.15;
//                       2. m_max_curve_vel = 0.8; m_min_curve_vel = 0.5; m_vel_slow_step = 0.1;
        void setMaxVelocity(float max_v);

        void setMaxObsVelocity(float max_obs_v);

        void setMaxCurveVelocity(float max_curve_vel);

        void setMaxCloudVelocity(float cmd_max_cloud_v);

        void setMaxTrajVelocity(float max_traj_v);

        void limitCLoudVelocity(float cloud_v);

        void setMaxElevatorVelocity(float value);

        void limitElevatorVelocity(bool limit);

        void setOffsetTrajOpt(bool enable_offset_traj);

        std::vector<Eigen::Vector2f> getFrontTraj();

        std::vector<Eigen::Vector2f> getOffsetTraj();

        std::pair<Traj_Select_Status, std::vector<Eigen::Vector2f>> getFeedTraj();

        std::vector<Eigen::Vector2f> calcFrontTraj(float front_dist);

        std::vector<Eigen::Vector2f> calcOffsetTraj(std::vector<Eigen::Vector2f> traj_points, float offset_dist);

        bool verifyTraj(const cv::Mat &obs_map, const std::vector<Eigen::Vector2f> &traj, float thresh_val);

        float getPointToLineDist(Eigen::Vector2f line_pt1, Eigen::Vector2f line_pt2, Eigen::Vector2f measure_pt);

        cv::Mat getDilateMap(const cv::Mat& obs_img, int dilate_radius);

        std::vector<Eigen::Vector2f> selectRefTraj(const cv::Mat& dilate_img, const PoseSE2& pose);

        void setPlannerParams(const std::string& json_file);

        bool getPathPlanTimeoutStatus();
        void clearPathPlanTimeoutStatus();

    private:
        void updatePlannerStates(PoseSE2 pose, Eigen::Vector2f speed, ObstacleGridMap static_map);
        void pathPlanThreadTask();
        void checkPathPlanTimeout(int16_t  timeout_limit_sec);
        PATH_PLAN_ERRCODE m_path_plan_timeout = PATH_PLAN_ERRCODE::NO_ERROR;
        bool m_path_plan_error = false ;

        IMotionPlanner *m_path_planner;
        IMotionPlanner *m_local_planner;
        ITrajTracker *traj_tracker;


        std::vector<Eigen::Vector2f> m_global_ref_traj;
        std::vector<Eigen::Vector2f> m_front_traj;
        std::vector<Eigen::Vector2f> m_offset_traj;
        std::vector<Eigen::Vector2f> m_theta_star_traj;
        std::vector<Eigen::Vector2f> m_feed_traj;

        int m_dilate_radius;
        Traj_Select_Status m_traj_select_status;

        std::atomic<bool> m_thread_is_running;
        std::atomic<bool> m_thread_is_finished;
        std::mutex m_indoor_planner_io;

        PoseSE2 m_planner_pose;
        Eigen::Vector2f m_planner_speed;
        ObstacleGridMap m_planner_map;

        int m_local_planner_status;
        int m_path_planner_status;
        std::atomic<bool> m_path_found;

        static constexpr float CALC_TRAJ_LENGTH = 2.5;
        static constexpr float CURVE_LINE_RATIO_THRESHOLD = 1.04;

        bool m_enable_offset_traj;
        static constexpr float_t M_P_OBS_COST_THRES = 0.302;
        static constexpr float_t MAX_OFFSET_POINT_DIST = 0.3; //max dist of offset traj two points
        static constexpr float_t MAX_TRAJ_DIST_TO_ROBOT = 0.4; //max traj point to robot
        static constexpr float_t CALC_OFFSET_TRAJ_DIST = 0.8;

        static constexpr float_t MAX_OTHER_TRAJ_VEL = 0.5f;
        static constexpr float_t MAX_FAILED_TRAJ_VEL = 0.3f;

//        float m_max_curve_vel;
        std::vector<int> m_curve_goal_id;

        CtrlCmd *m_ctrl_cmd;
    };
}}

#endif //MOTIONPLANNER_MOTIONPLANNER_H
