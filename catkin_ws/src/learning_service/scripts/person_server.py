#!/usr/bin/env python
import rospy
from learning_service.srv import Person, PersonResponse

def personCallback(req):
    # show request
    rospy.loginfo("Person: name:%s  age:%d  sex:%d", req.name, req.age, req.sex)

    # return response
    return PersonResponse("OK")

def person_server():
    # ROS node init
    rospy.init_node("person_server")

    # create server /person_server, callback function is personCallback
    s = rospy.Service('/show_person', Person, personCallback)

    # loop wait
    print "Ready to receive person information."
    rospy.spin()

if __name__ == '__main__':
    person_server()
