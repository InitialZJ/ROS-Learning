#!/usr/bin/env python
import rospy
import thread, time
from geometry_msgs.msg import Twist
from std_srvs.srv import Trigger, TriggerResponse

pubCommand = False
turtle_vel_pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)

def command_thread():
    while True:
        if pubCommand:
            vel_msg = Twist()
            vel_msg.linear.x = 0.5
            vel_msg.angular.z = 0.2
            turtle_vel_pub.publish(vel_msg)

        time.sleep(0.1)

def commadnCallback(req):
    global pubCommand
    pubCommand = bool(1 - pubCommand)

    # show request
    rospy.loginfo("Publish turtle velocity command! [%d]", pubCommand)

    # return response
    return TriggerResponse(1, "Change turtle command state!")

def turtle_command_server():
    # ROS node init
    rospy.init_node("turtle_command_server")

    # create server /turtle_command, callback function is commandCallback
    s = rospy.Service('/turtle_command', Trigger, commadnCallback)

    # loop wait
    print "Ready to receive turtle command."

    thread.start_new_thread(command_thread, ())
    rospy.spin()

if __name__ == '__main__':
    turtle_command_server()
