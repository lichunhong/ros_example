## Four-wheel steering Controller ##

Controller for a four_wheel_steering mobile base.

The mobile base is 4ds and can move with zero turning radius. 

Front and rear wheel steer angle is opposite

运动模式为 前后轮转角相反模式，可以实现任意转弯半径的运动


使用方法：


模型启动：roslaunch four_wheel_steering_controller view_four_wheel_steering.launch


接收的话题（1）输入为（v,w）
订阅的话题为：/four_wheel_steering_controller/cmd_vel；消息格式为：geometry_msgs/Twist


其中linear.x对应v， angular.z对应w


接收的话题（2）输入为 前后轮转角和转速
订阅的话题为：/four_wheel_steering_controller/cmd_four_wheel_steering；消息格式为：four_wheel_steering_msgs/FourWheelSteering


一般使用第一种方式。
