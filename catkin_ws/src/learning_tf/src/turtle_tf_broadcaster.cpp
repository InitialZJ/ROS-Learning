/**
 * make tf data, and calculate, publish
 */
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <turtlesim/Pose.h>

std::string turtle_name;

void poseCallback(const turtlesim::PoseConstPtr& msg)
{
    // create tf broadcaster
    static tf::TransformBroadcaster br;

    // init tf data
    tf::Transform transform;
    transform.setOrigin(tf::Vector3(msg->x, msg->y, 0.0));
    tf::Quaternion q;
    q.setRPY(0, 0, msg->theta);
    transform.setRotation(q);

    // broadcast tf data between world and turtle
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", turtle_name));
}

int main(int argc, char** argv)
{
    // init ROS node
    ros::init(argc, argv, "my_tf_broadcaster");

    // input turtle_name
    if (argc != 2)
    {
        ROS_ERROR("need turtle name as argument");
        return -1;
    }

    turtle_name = argv[1];

    // subscribe turtle pose topic
    ros::NodeHandle node;
    ros::Subscriber sub = node.subscribe(turtle_name + "/pose", 10, &poseCallback);

    // loop wait
    ros::spin();

    return 0;
}