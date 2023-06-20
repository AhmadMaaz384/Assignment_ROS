#!/bin/bash

cd ~/catkin_ws
source devel/setup.bash
export TURTLEBOT3_MODEL=burger

# Open a new terminal tab and run the first launch file
gnome-terminal --tab --title="turtlebot3_world.launch" --command="bash -c 'roslaunch turtlebot3_gazebo turtlebot3_world.launch'"

# Wait for a few seconds to allow the first launch file to start
sleep 2


export TURTLEBOT3_MODEL=burger

# Open a new terminal tab and run the second launch file
gnome-terminal --tab --title="turtlebot3_navigation.launch" --command="bash -c 'roslaunch turtlebot3_navigation turtlebot3_navigation.launch map_file:=$HOME/catkin_ws/src/simple_navigation_goals/map/map.yaml'"
