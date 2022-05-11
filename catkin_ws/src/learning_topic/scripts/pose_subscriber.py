#!/usr/bin/env python
import rospy
from turtlesim.msg import Pose

def poseCallback(msg):
    rospy.loginfo("Turtle pose: x:%0.6f, y:%0.6f", msg.x, msg.y)

def pose_subscriber():
    # ROS node init
    rospy.init_node('pose_subscriber', anonymous=True)

    # create Subscriber, topic /turtle/pose, callback function poseCallback
    rospy.Subscriber("/turtle1/pose", Pose, poseCallback)

    # wait
    rospy.spin()

if __name__ == '__main__':
    pose_subscriber()