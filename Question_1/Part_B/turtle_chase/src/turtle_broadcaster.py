#!/usr/bin/env python  
import roslib
roslib.load_manifest('turtle_chase')
import rospy
import tf
from turtlesim.msg import Pose

def handle_turtle_pose(msg, turtlename):
    br.sendTransform((msg.x, msg.y, 0),
                     tf.transformations.quaternion_from_euler(0, 0, msg.theta),
                     rospy.Time.now(),
                     turtlename,
                     "world")

if __name__ == '__main__':   
    rospy.init_node('turtle_tf_broadcaster')
    
    br = tf.TransformBroadcaster()

    turtlename = rospy.get_param('~turtle')
    rospy.Subscriber('/%s/pose' % turtlename,
                     Pose,
                     handle_turtle_pose,
                     turtlename)
   
    rate = rospy.Rate(10.0)
    while not rospy.is_shutdown():
        br.sendTransform((-0.8, 0.0, 0.0),
                         (0.0, 0.0, 0.0, 1.0),
                         rospy.Time.now(),
                         "reference_frame",
                         "turtle1")
        rate.sleep()    
    rospy.spin()
