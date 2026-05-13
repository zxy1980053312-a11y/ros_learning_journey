#include "ros/ros.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"paramset");
    ros::NodeHandle NH;
    //增加参数
    //方案1
    NH.setParam("type","危险流浪者");
    NH.setParam("height",200);
    //方案2
    ros::param::set("type_p","暴风赤红");
    ros::param::set("height_p",230);

    //修改
    //1
     NH.setParam("height",201);
    //2
    ros::param::set("height_p",231);
    return 0;
}
