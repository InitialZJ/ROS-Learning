/**
* publish /person_info topic, msg type: learning_topic/Person
*/
#include <ros/ros.h>
#include "learning_topic/Person.h"

int main(int argc, char **argv)
{
    // ROS node init
    ros::init(argc, argv, "person_publisher");

    // create node handler
    ros::NodeHandle n;

    // createt publisher, send topic
    ros::Publisher person_info_pub = n.advertise<learning_topic::Person>("/person_info", 10);

    // set loop rate
    ros::Rate loop_rate(1);

    int count = 0;
    while (ros::ok())
    {
        // inti Person
        learning_topic::Person person_msg;
        person_msg.name = "Tom";
		person_msg.age = 18;
		person_msg.sex = learning_topic::Person::male;


        // publish
        person_info_pub.publish(person_msg);
        ROS_INFO("Publish Person Info name:%s  age:%d  sex:%d", person_msg.name.c_str(), person_msg.age, person_msg.sex);

        // sleep
        loop_rate.sleep();
    }
    
    return 0;
}
