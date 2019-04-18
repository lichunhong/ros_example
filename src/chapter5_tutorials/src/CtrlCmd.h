//
// Created by root on 2/25/19.
//

#ifndef MOTIONPLANNER_CTRLCMD_H
#define MOTIONPLANNER_CTRLCMD_H


#include <Eigen/Dense>

namespace ninebot_algo{
    namespace motion_planner {

        class CtrlCmd {

        public:
            CtrlCmd();

            float getMixMaxV();

            void limitMaxObsV(bool is_limited);

            void limitCurveV(bool is_limited);
            void limitElevatorV(bool in_elevator);

            void limitCloudV(float cloud_v);
            void limitCloudV(bool is_limited);

            void setTrajV(float traj_v);
            void limitTrajV(bool is_limited);

            void setMaxV(float_t max_v);
            void setMaxObsV(float_t max_obs_v);
            void setMaxCurveV(float_t max_curve_v);
            void setMaxCloudV(float_t max_cloud_v);
            void setMaxTrajV(float_t max_traj_v);
            void setMaxElevatorV(float_t value);

        private:
            /**
             * m_max_v:
             * m_max_w:
             * m_max_obs_v:
             * m_max_curve_v:
             * m_max_cloud_v:
             * m_max_traj_v:
             */
            static constexpr float WRONG_MAX_V = 0.3;
            float m_max_v;

            float m_max_obs_v;
            float m_max_curve_v;
            float m_max_cloud_v;
            float m_max_traj_v;
            float m_max_elevator_v;

            float m_obs_v;
            float m_curve_v;
            float m_cloud_v;
            float m_traj_v;
            float m_elevator_v;

//            Eigen::Vector2f m_previous_cmd;
//            Eigen::Vector2f m_cmd_limit_out;
//            Eigen::Vector2f m_final_cmd;
        };
    }}

#endif //MOTIONPLANNER_CTRLCMD_H
