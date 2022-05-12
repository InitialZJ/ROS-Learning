#!/usr/bin/env python
import sys
import rospy
from std_srvs.srv import Empty

def parameter_config():
    # ROS node init
    rospy.init_node('parameter_config', anonymous=True)

    # read color
    red = rospy.get_param('/turtlesim/background_r')
    green = rospy.get_param('/turtlesim/background_g')
    blue = rospy.get_param('/turtlesim/background_b')

    rospy.loginfo("Get color [%d, %d, %d]", red, green, blue)

    # set color
    rospy.set_param('/turtlesim/background_r', 255)
    rospy.set_param('/turtlesim/background_g', 255)
    rospy.set_param('/turtlesim/background_b', 255)

    rospy.loginfo("Set color [255, 255, 255]")

    # read color again
    red = rospy.get_param('/turtlesim/background_r')
    green = rospy.get_param('/turtlesim/background_g')
    blue = rospy.get_param('/turtlesim/background_b')

    rospy.loginfo("Re-get color [%d, %d, %d]", red, green, blue)

    # refresh color
    rospy.wait_for_service('/clear')
    try:
        clear_background = rospy.ServiceProxy('/clear', Empty)

        # send request
        clear_background()
    except rospy.ServiceException, e:
        print "Service call failed: %s" % e

if __name__ == '__main__':
    parameter_config()