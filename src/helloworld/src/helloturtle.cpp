#include "ros/ros.h"
int main(int argc,char *argv[])
{
    ros::init(argc,argv,"helloturtle");
    ROS_INFO("turtle is ready");
    return 0;
}