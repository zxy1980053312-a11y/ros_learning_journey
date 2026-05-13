#include "ros/ros.h"
#include "plumbing_pub_sub/person.h"

void domsg(const plumbing_pub_sub::person::ConstPtr& person)
{
    ROS_INFO("听到的消息如下：姓名：%s，年龄：%d,身高：%.2f",person->name.c_str(),person->age,person->height);
}
int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"sub02");
    ros::NodeHandle NH;
    ros::Subscriber sub = NH.subscribe("ququ",10,domsg);
    ros::spin();
}