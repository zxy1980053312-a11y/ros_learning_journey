#include "ros/ros.h"

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"getparam");
    ros::NodeHandle nh;
    std::vector<std::string> names;
    nh.getParamNames(names);
    for(auto &&name : names)
    {
        ROS_INFO("获取到的元素如下：%s",name.c_str());
    }
    std::string key;
    nh.searchParam("type",key);
    ROS_INFO("搜索结果：%s",key.c_str());
    return 0;
}
