#!/usr/bin/env python
import rospy
from learning_topic.msg import Person

def person_publisher():
    # init
    rospy.init_node('person_publisher', anonymous=True)

    # create Publisher
    person_info_pub = rospy.Publisher('/person_info', Person, queue_size=10)

    # set rate
    rate = rospy.Rate(1)

    while not rospy.is_shutdown():
        # init message
        person_msg = Person()
        person_msg.name = "Tom"
        person_msg.age = 18;
        person_msg.sex = Person.male;

        # publish
        person_info_pub.publish(person_msg)
        rospy.loginfo("Publish person message[%s, %d, %d]", person_msg.name, person_msg.age, person_msg.sex);

        # sleep
        rate.sleep()

if __name__ == '__main__':
    try:
        person_publisher()
    except rospy.ROSInterruptException:
        pass
        
