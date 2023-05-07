#include "ros/ros.h"
#include "server_client/addints.h"

/*
    服务端实现：解析客户端提交的数据，并且运算产生响应
        1.头文件
        2.初始化ros节点
        3.创建节点句柄
        4.创建服务对象
        5.处理请求并响应
        6.spin()
*/

bool donums(server_client::addints::Request &request,
            server_client::addints::Response &response)
{
    // 1.处理请求

    // 2.处理相应
    return true;
}



int main(int argc, char *argv[])
{
        // 1.头文件
        // 2.初始化ros节点
    ros::init(argc,argv,"baojie");//节点名称保证唯一
        // 3.创建节点句柄
    ros::NodeHandle jb;
        // 4.创建服务对象
    ros::ServiceServer server = jb.advertiseService("addints"/*话题名称*/
                                                    ,donums/*回调函数 返回值是bool型*/);
        // 5.处理请求并响应
        // 6.spin()
    ros::spin();
    return 0;
}
