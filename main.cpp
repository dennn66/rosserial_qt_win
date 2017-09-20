/*
 *
 *
 *
 */


#include <QCoreApplication>
#include "ros.h"
#include <geometry_msgs/Twist.h>
#include <windows.h>

double dX = 0;
double dTh = 0;

void messageCb(const geometry_msgs::Twist& msg){

      printf("Recieved linear.x %f\n", msg.linear.x);

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ros::NodeHandle nh;
    char *ros_master = "10.0.2.4";
    printf("Connecting to server at %s\n", ros_master);
    nh.initNode(ros_master);


    printf("Advertising cmd_vel message\n");
    geometry_msgs::Twist twist_msg;
    ros::Publisher cmd_vel_pub("r1/cmd_vel", &twist_msg);
    ros::Subscriber<geometry_msgs::Twist> sub("r1/cmd_vel", &messageCb);
    nh.advertise(cmd_vel_pub);
    nh.subscribe(sub);



    printf("Go robot go!\n");
    while (1)
    {
        dX++;
        twist_msg.linear.x = dX;
        twist_msg.linear.y = 0;
        twist_msg.linear.z = 0;
        twist_msg.angular.x = 0;
        twist_msg.angular.y = 0;
        twist_msg.angular.z = dTh;
        cmd_vel_pub.publish(&twist_msg);

        nh.spinOnce();
        Sleep(100);
        printf(".");
    }
    return a.exec();
}
