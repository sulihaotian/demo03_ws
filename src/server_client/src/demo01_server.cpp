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
    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("受到的数据  %d  %d",num1,num2);
    // 2.处理相应
    response.sum= num1+num2;
    ROS_INFO("求和结果  %d",response.sum);
    return true;
}



int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

        // 1.头文件
        // 2.初始化ros节点
    ros::init(argc,argv,"baojie");//节点名称保证唯一
        // 3.创建节点句柄
    ros::NodeHandle jb;
        // 4.创建服务对象
    ros::ServiceServer server = jb.advertiseService("addints"/*话题名称*/
                                                    ,donums/*回调函数 返回值是bool型*/);
    ROS_INFO("服务器已启动");
        // 5.处理请求并响应-->回调函数
        // 6.spin()
    ros::spin();
    return 0;
}
