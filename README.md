# Assignment_ROS (Melodic)
**To run all the questions, do the following steps:**

Download and Extract the **All_Packages.zip** file in the catkin_ws/src folder.

After extracting, 4 files will be visible. 

Run the terminal and type the following command:

    cd ~/catkin_ws
    source devel/setup.bash
    cd ~/catkin_ws/src
    chmod +x first_script.sh
    ./first_script.sh
     
This bash file install all the required packages.

Now run the following command:
     
      cd ~/catkin_ws
      source devel/setup.bash
      catkin_make
     
All the packages will get build.

## Question 1
### Part A

Open the terminal and run:

    cd ~/catkin_ws
    source devel/setup.bash 
    roslaunch turtle_chase two_turtles.launch
    
This launch file launces two nodes i.e Turtlesim and turtlesim_teleop and will run the turtlesim node with two turtles in a single window. 

### Part B

Open the terminal and run:

     cd ~/catkin_ws
     source devel/setup.bash
     roscd turtle_chase/src
     chmod +x turtle_broadcaster.py
     chmod +x turtle_listener.py
     roslaunch turtle_chase chase.launch
    
This launch file launches turtlesim window with two turtles in it. If user teleops the turtle1, the turtle2 follows it and maintains a distance of 0.8 meters from behind the turtle1

## Question 2
### Part A

Question 2 Part A is just to ensure that the environment for the turtle3 robot works fine and it navigates to a nav_goal point in Rviz.

A map is generated by teleoping the **Turtlebot3 Burger** in **Turtlebot3 World Environment**

This map is being used in the question 2 part B for navigation using a C++ script.

### Part B
#### Inside the **simple_navigation_goals** folder, there is a **map** folder. Copy the **map.pgm** and **map.yaml** to the HOME location.

Now navigate to the following folder:
    
    catkin_ws/src/simple_navigation_goals/bash file
    
Now open a terminal there and type:
    
    chmod +x myscript.sh
    ./myscript.sh

This bash file will run the Gazebo with **Turtlebot3 World Environment** and also launches the Rviz loaded with the map we just copied to HOME location.


**Click the 2d Pose Estimate Button and give an initial estimate**

Now open a new tab in the terminal and type:

     cd ~/catkin_ws
     source devel/setup.bash 
     roslaunch simple_navigation_goals navigation.launch
    
A prompt will be given asking the user to **enter a valid goal point**.

Enter point 1, 2 or 3 and the Burger robot will move to the respective goal points.

This will


