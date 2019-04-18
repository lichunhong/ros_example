/*
 * Public Content
 */

#ifndef MOTIONPLANNER_NINEBOTALGOMP_H
#define MOTIONPLANNER_NINEBOTALGOMP_H


/* 1.Macro Switch
 *      1.1 Use cleaned cells
 *      1.2 Use theta* with dwa
 *      1.3 Use curve slow down
 *      1.4 Use offset path
 * */

// 1.1
#define DELETED_DUPLICATE_CELLS
// 1.2
#define USE_PATH_PLAN
#ifdef USE_PATH_PLAN
    #define DWA_THETA_STAR
#endif
//1.3
#define TRAJ_CURVE_SLOW
//1.4
#define USE_OFFSET_PATH
//1.5
#define NEW_OBS_COST

/* 2.Const Variable */
#define M_P_NUM_V 7
#define M_P_NUM_W 11

namespace ninebot_algo{
    namespace motion_planner {

        /* 3.Public Enum */
        enum TypeRobot
        {
            Cylinder = -1,
            G1 = 0,
            Go = 1,
            GX = 2,
            GX_EVT4 = 3,
            GX_EVT4_5 = 4
        };

        enum class PATH_PLAN_ERRCODE {
            NO_ERROR = 0,
            TIMEOUT_ERROR
        };

        enum PLANNER_STATUS
        {
            planner_unknown = 0, ///< brief unknown
            planner_normal = 1, ///< breif get normal trajectory
            goal_have_reached = 2, ///< breif reach the goal
            goal_not_find = 3,///< breif find no goal in search max range
            goal_invalid = 4, ///< breif all way points in obstacle
            update_failed = 5, ///< update state failed
            traj_invalid = 6,
            abnormal = 7
        };

        enum CONTROLLER_TYPE
        {
            DWA = 1,
            straight_move = 2,
            naive_move = 3, // i.e., turn-go-turn
            PID = 4,
            go_straight_nonstop = 5,
            PID_straight = 6,
            pure_rotate = 7,
            turn_and_go = 8,
            straight_and_DWA = 9
        };

        enum CELL_STATUS
        {
            free = 0,
            goal = 1,
            undetected = 2,
            occupancy
        };

        enum class BackwardState
        {
            Available = 0,
            Invalid =1,
            Collision = 2
        };
        enum class RotateState
        {
            Available = 0,
            Finished =1,
            Collision = 2
        };

        enum class ABNORMAL_STATUS
        {
            normal = 0,
            go_further_from_target = 1,
            abnormal_angular_speed = 2,
            abnormal_orientation = 3,
            relative_odometer = 4
        };

        enum CUR_GOAL_STATUS
        {
            cur_goal_normal = 0,
            cur_goal_not_find = 1,
            cur_goal_invalid = 2,
            cur_goal_arrived = 3
        };

        enum class TS_Path_Status {
            Path_Found = 0,
            Status_Unknown,
            Goal_Arrived,
            Variable_Error,
            Map_Error,
            Goal_Error,
            Maze_Error,
            No_Path
        };

        enum class TS_Goal_Status {
            Goal_Found = 0,
            Goal_Arrived,
            Goal_Error
        };

        enum class Traj_Select_Status
        {
            Original_Traj = 0,
            Offset_Traj,
            Theta_Star_New, // theta* found new traj
            Theta_Star_Erase, // theta* found old traj update with robot pose
            Theta_Star_Over, // Finish all theta* points
            Failed
        };

        /* 4.Public Typedef */
        typedef std::pair<int, int> Cell;
        typedef std::vector<Cell> PointCell;
        typedef std::vector<PointCell> TrajCell;
        typedef std::vector<TrajCell> TrajsCell;
    }
}

#endif //MOTIONPLANNER_NINEBOTALGOMP_H
