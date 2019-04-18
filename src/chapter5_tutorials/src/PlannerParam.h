//
// Created by root on 4/3/19.
//

#ifndef MOTIONPLANNER_PLANNERPARAM_H
#define MOTIONPLANNER_PLANNERPARAM_H


#include <string>
#include <functional>
#include "cpp_util/json.hpp"


namespace ninebot_algo{ namespace motion_planner {

    class PlannerParamInterface {
    public:
        virtual void setParam() = 0;
    };

    template<typename T>
    class PlannerParam : public PlannerParamInterface {
    public:
        PlannerParam(const json::JSON planner_json_,
                     const std::string param_key_,
                     std::function<void(T)> set_func_,
                     const T &default_val_) :
                planner_json(planner_json_),
                param_key(param_key_),
                set_func(set_func_),
                default_val(default_val_) {}

        void setParam() override;

    private:
        json::JSON planner_json;
        std::string param_key;
        std::function<void(T)> set_func;
        T default_val;
    };

}}
#endif //MOTIONPLANNER_PLANNERPARAM_H
