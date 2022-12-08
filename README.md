# Template for making your own ROS packages

## Prerequisites
- Have Ubuntu and ROS installed

## Cloning the repo
From home directory create /your_pkg_ws/src folder and run the following command
```
mkdir -p your_pkg_ws/src
cd your_pkg_ws/src
git clone "your_pkg_repo_link"
```

## Updating Dependencies
```
cd ~/your_pkg_ws/
rosdep update
rosdep install --from-paths src --ignore-src -r -y --rosdistro noetic
```

## Installing Controllers For Robot
```
sudo apt-get update
sudo apt-get install ros-noetic-ros-controllers
```


## Building tutorial package
First build the project and source the setup file so that the system knows where to look for your build files
```
cd ~/your_pkg_ws
catkin build your_pkg_name
source devel/setup.bash
```

## Launch the robot
```
roslaunch your_pkg_name gazebo.launch
```


## Commands used during tutorial
useful tip: press tab to auto-complete words as you type commands
Open a new terminal to run commands for the robot

```
cd ~/your_pkg_ws
source devel/setup.bash
```
To run the main node run this command
```
rosrun your_pkg_ws controller
```

To send a command to the base
```
rostopic pub /base_controller/command std_msgs/Float64 "data: 1.0"
```

To see the ROS node tree run this command
```
rqt_graph
```
# Commit to this repository

Go to ~/your_pkg_ws/src/your_pkg_name and run this commands in terminal
```
git status
git add .
git status
git commit -m "type your message here"
```
