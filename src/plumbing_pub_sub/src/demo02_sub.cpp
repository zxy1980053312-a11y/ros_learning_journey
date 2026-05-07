#include "ros/ros.h"
#include "std_msgs/String.h"

void doMSG(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("接收到的消息：%s",msg->data.c_str());
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"sub01");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("topic1",10,doMSG);
    ros::spin();
}