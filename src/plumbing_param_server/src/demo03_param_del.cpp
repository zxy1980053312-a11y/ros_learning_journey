#include "ros/ros.h"

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"paramdel");
    ros::NodeHandle nh;
    bool flag1 = nh.deleteParam("type_p");
    if (flag1)
    {
        ROS_INFO("删除成功！");
    }
    else
    {
        ROS_INFO("删除失败。。");
    }
    
    return 0;
}
