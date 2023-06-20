#!/usr/bin/env python  
import roslib
roslib.load_manifest('turtle_chase')
import rospy
import math
import tf
from geometry_msgs.msg import Twist
import turtlesim.srv
from turtlesim.msg import Pose

def turtle1_pose_callback(msg):
    x1 = msg.x
    x2 = turtle2_pose.x
    y1 = msg.y
    y2 = turtle2_pose.y
    distance = math.sqrt((x2 - x1)**2 + (y2 - y1)**2)
    print("(Use keyboard to move turtle1) Distance b/w both turtles:", distance)
    
def turtle2_pose_callback(msg):
    global turtle2_pose
    turtle2_pose = msg


if __name__ == '__main__':
    rospy.init_node('turtle_tf_listener')

    listener = tf.TransformListener()

    rospy.wait_for_service('spawn')
    spawner = rospy.ServiceProxy('spawn', turtlesim.srv.Spawn)
    spawner(1, 5.5, 0, 'turtle2')

    turtle_vel = rospy.Publisher('turtle2/cmd_vel', Twist,queue_size=1)

    turtle1_pose = Pose()
    turtle2_pose = Pose()
    rospy.Subscriber('turtle1/pose', Pose, turtle1_pose_callback)
    rospy.Subscriber('turtle2/pose', Pose, turtle2_pose_callback)

    rate = rospy.Rate(10.0)
    while not rospy.is_shutdown():
        try:
            (trans,rot) = listener.lookupTransform('/turtle2', '/reference_frame', rospy.Time(0))
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            continue

        angular = 5 * math.atan2(trans[1], trans[0])
        linear = (0.8 * math.sqrt(trans[0] ** 2 + trans[1] ** 2)) 
        if angular <= 0.01 and angular >= -0.01 and linear < 0.0001 and linear > -0.0001:
            angular = 0 
            linear = 0

        cmd = Twist()
        cmd.linear.x = linear
        cmd.angular.z = angular
        turtle_vel.publish(cmd)

        rate.sleep()
