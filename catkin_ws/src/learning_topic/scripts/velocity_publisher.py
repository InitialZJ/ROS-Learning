#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist

def velocity_publisher():
    # init
    rospy.init_node('velocity_publisher', anonymous=True)

    # create Publisher
    turtle_vel_pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)

    # set rate
    rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        # init message
        vel_msg = Twist()
        vel_msg.linear.x = 0.5
        vel_msg.angular.z = 0.2

        # publish
        turtle_vel_pub.publish(vel_msg)
        rospy.loginfo("Publish turtle velocity command[%0.2f m/s, %0.2f rad/s]", vel_msg.linear.x, vel_msg.angular.z)

        # sleep
        rate.sleep()

if __name__ == '__main__':
    try:
        velocity_publisher()
    except rospy.ROSInterruptException:
        pass
        
