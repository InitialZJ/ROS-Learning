/**
* publish turtle1/cmd_vel topic, msg type: geometry_msgs::Twist
*/
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
    // ROS node init
    ros::init(argc, argv, "velocity_publisher");

    // create node handler
    ros::NodeHandle n;

    // createt publisher, send topic
    ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    // set loop rate
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok())
    {
        // inint Twist
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x = 0.5;
        vel_msg.angular.z = 0.2;

        // publish
        turtle_vel_pub.publish(vel_msg);
        ROS_INFO("Publish turtle velocity command[%0.2f m/s, %0.2f rad/s]", vel_msg.linear.x, vel_msg.angular.z);

        // sleep
        loop_rate.sleep();
    }
    
    return 0;
}