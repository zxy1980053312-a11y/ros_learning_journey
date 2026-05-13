#include "ros/ros.h"
#include "plumbing_pub_sub/person.h"

int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"pub02");
    ros::NodeHandle NH;
    ros::Publisher pub = NH.advertise<plumbing_pub_sub::person>("ququ",10);
    plumbing_pub_sub::person person;
    person.age = 1;
    person.name = "桃芝芝莓莓";
    person.height = 1.78;
    ros::Rate rate(1);
    while(ros::ok())
    {
        pub.publish(person);
        person.age += 1;
        ROS_INFO("人物信息：%s,%d,%.2f",person.name.c_str(),person.age,person.height);
        rate.sleep();
    }

}