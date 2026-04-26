#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"pub01");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("topic1",10);
    std_msgs::String msg;
    while(ros::ok())
    {
        msg.data = "hello,this is the first try for pub";
        pub.publish(msg);
    }

}