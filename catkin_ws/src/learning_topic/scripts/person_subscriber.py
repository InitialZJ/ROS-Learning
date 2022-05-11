#!/usr/bin/env python
import rospy
from learning_topic.msg import Person

def personInfoCallback(msg):
    rospy.loginfo("Subscribe Person Info: name:%s  age:%d  sex:%d", msg.name, msg.age, msg.sex)

def person_subscriber():
    # ROS node init
    rospy.init_node('person_subscriber', anonymous=True)

    # create Subscriber, topic /person_subscriber, callback function poseCallback
    rospy.Subscriber("/person_info", Person, personInfoCallback)

    # wait
    rospy.spin()

if __name__ == '__main__':
    person_subscriber()