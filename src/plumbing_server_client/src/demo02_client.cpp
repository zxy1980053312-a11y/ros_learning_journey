#include "ros/ros.h"
#include "plumbing_server_client/addints.h"

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    if(argc != 3)
    {
        ROS_INFO("提交失败：参数个数错误");
        return 1;
    }
    ros::init(argc,argv,"client1");
    ros::NodeHandle NH;
    ros::ServiceClient client = NH.serviceClient<plumbing_server_client::addints>("addints");
    plumbing_server_client::addints addints;
    addints.request.num1 = atoi(argv[1]);
    addints.request.num2 = atoi(argv[2]);
    client.waitForExistence();
    ros::service::waitForService("addints");
    bool flag = client.call(addints);
    if(flag)
    {
        ROS_INFO("响应成功！");
        ROS_INFO("加合结果为%d",addints.response.sum);
    }
    else
    {
        ROS_INFO("响应失败.....");
    }
    return 0;
}
