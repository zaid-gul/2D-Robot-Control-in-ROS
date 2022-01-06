# Research Track I - first assignment
Controlling a holonomic robot in a 2d space with a simple 2d simulator, StageROS. 
![alt text](https://github.com/zaidgul/assignment1/blob/main/Simulator.jpg?raw=true)
## Overview
1. The robot asks for a random target, with both coordinates in the interval (-6.0, 6.0).
2. The robot reaches the target.
3. Go to step 1.

## Computational Graph
![alt text](https://github.com/zaidgul/assignment1/blob/main/rosgraph.png?raw=true)

## Contents of the Package
- **random_point_server.cpp:** Node used for generating random coordinates in the interval (-6.0, 6.0)
- **holo_robot.cpp:** Node used for controlling the robot and making it reach the target coordinates 
- **target.srv:** Custom service file for x and y coordinates
- **exercise.world:** File for simulator 
## How to run the code
First go the ROS workspace and type this command:
```
catkin_make
```
Execute the ROS Master with this command:
```
roscore &
```
Launch the 2d simulator called StageROS using the following command:
```
rosrun stage_ros stageros $(rospack find assignment1)/world/exercise.world
```
Next, type the following command to execute random_point_server node:
```
rosrun assignment1 random_point_server
```
Finally, type the following command to execute the holo_robot node:
```
rosrun assignment1 holo_robot
```
## Requirements
- Ubuntu (Linux) or Docker Image https://hub.docker.com/r/carms84/rpr
- ROS (Robot Operating System) http://wiki.ros.org/
