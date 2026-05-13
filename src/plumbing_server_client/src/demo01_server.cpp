#include "ros/ros.h"
#include "plumbing_server_client/addints.h"


bool dosum(plumbing_server_client::addints::Request &request,
           plumbing_server_client::addints::Response &response )
{
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("获取到的数据num1 = %d, num2 = %d ",num1,num2);
    int sum = num1 + num2;
    response.sum = sum;
    ROS_INFO("求和服务响应数据为 %d", sum);
    return true;
}

int main(int argc,char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"server1");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("addints",dosum);
    ROS_INFO("服务端已启动");
    ros::spin();

    return 0;
}