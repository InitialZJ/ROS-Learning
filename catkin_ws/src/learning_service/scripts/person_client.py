#!/usr/bin/env python
import rospy
from learning_service.srv import Person, PersonRequest

def person_client():
    # ROS node init
    rospy.init_node("person_client")

    # wait for /show_person service, create a client, connect the /show_person service
    rospy.wait_for_service('/show_person')
    try:
        person_client = rospy.ServiceProxy('/show_person', Person)

        # send request
        response = person_client("Tom", 20, PersonRequest.male)
        return response.result
    except rospy.ServiceException, e:
        print "Service call failed: %s" % e

if __name__ == '__main__':
    # show result
    print "Show person result : %s" % (person_client())
