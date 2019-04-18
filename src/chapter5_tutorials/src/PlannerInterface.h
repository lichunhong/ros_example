//
// Created by root on 11/7/18.
//

#ifndef MOTIONPLANNER_PLANNERINTERFACE_H
#define MOTIONPLANNER_PLANNERINTERFACE_H

#include <Eigen/Dense>
#include <cv.h>
#include <cstdint>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "NinebotAlgoMP.h"

namespace ninebot_algo { namespace motion_planner{

    typedef Eigen::Vector2f Point2D;
    typedef Eigen::Vector3f PoseSE2;
    typedef std::pair<long, PoseSE2> StampedPoseSE2;

    class IPlannerParam {
    public:
        virtual ~IPlannerParam(){}
    };

    class IRobotProfile {
    public:
        virtual ~IRobotProfile(){}
    };

    class Trajectory {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        Trajectory();
//        Trajectory(int id = 0, long timestamp = 0);
        ~Trajectory();
        int id;
        long timestamp;

        int addPose(PoseSE2 pose, long ts=0);
        int addPose(float x, float y, float theta, long ts=0);
        int addPose(std::vector<PoseSE2> pose);
        int addPose(std::vector<StampedPoseSE2> pose);

        int getSize();
        float getLength();
        PoseSE2 getPoseById(int idx);
        StampedPoseSE2 getStampedPoseById(int idx);
        StampedPoseSE2 getStampedPoseByTime(int time);
        std::vector <Eigen::Vector2f> toPoints2D();
//    private:
        std::vector <StampedPoseSE2> way_points;
    };




    enum class GeoType{
        Unkown,
        Grid,
        Polygon
    };

    class IGeoShape{
    public:
        IGeoShape(GeoType t=GeoType::Unkown) : type(t){}

        virtual ~IGeoShape(){}
        virtual void moveBy(PoseSE2 trans_pose) = 0;
        virtual float collideCost(IGeoShape& object, PoseSE2 pose) = 0;

        GeoType type;
    };

    class IObstacleMap : public IGeoShape{
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        IObstacleMap(GeoType t=GeoType::Unkown):
                IGeoShape(t){
            range_x = 0; range_y = 0;
        }
        IObstacleMap(GeoType t, IObstacleMap& map);

        virtual ~IObstacleMap(){}

        virtual int crop(PoseSE2 center, Eigen::Vector2f range, IObstacleMap& output) = 0;
        virtual void moveBy(PoseSE2 trans_pose) override {};
        virtual float collideCost(IGeoShape& object, PoseSE2 pose){ return 0;};

        float range_x;
        float range_y;
    };

    class IMotionPlanner {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW

        /* Set robot profile (motion constrains, shape, etc). */
//        virtual void setRobotProfile(IRobotProfile &profile)=0;

        /* Set reference trajectory. */
        virtual void setReferenceTrajectory(Trajectory &traj)=0;

        /* Try to plan a path. return 0 when success. */
        virtual int makePlan(PoseSE2 pose, Eigen::Vector2f speed, IObstacleMap& static_map)=0;

        /* get planned trajectory. */
        virtual Trajectory getOptimalTrajectory()=0;

        /* get motion command. This can drive the robot toward target without low level controller.*/
        virtual Eigen::Vector2f getOptimalControlCmd()=0;

        virtual PoseSE2 getCurrentTarget() = 0;

        virtual ~IMotionPlanner() {}
    };

    class ITrajTracker {

    };
}}
#endif //MOTIONPLANNER_PLANNERINTERFACE_H
