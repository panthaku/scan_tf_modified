#Run roscore as a mandatory step in one Terminal 

#Scan_tf_modified
#Belwo steps are involved in the process to modify the contents of ROS BAG

# step 1
catkin_make -DACTUAL_HECTOR_PROVIDED_BAG=ON
# step 2
RUN The node created in step 1
# spep 3
Start recording the bag to  scan_and_tf_from_actual_hector_slam_bag.bag by running the command belwo
rosbag record /scan_data /tf_data

# Step 4
Play the downloaded Hector bag
stop the node which was started in step 2


# step 5 
catkin_make -DACTUAL_HECTOR_PROVIDED_BAG=OFF 

# step 6
RUN The node created in  step 5

# step 7 
Start recording the bag to  converted_ros_bag.bag by running the command belwo
rosbag record /scan /tf

# step 8
Play the non_hector_slam_bag.bag  created in step 4
stop the node which was started in step 6

We have two bags ready now which we can run against hector slam library 
roslaunch hector_slam_launch tutorial.launch                        
Play the bag converted in step 3 and step 7 both should be able to drive the robot
 
We have two bags ready now which we can run against hector slam library 
roslaunch hector_slam_launch tutorial.launch                        
Play the bag converted in step 3 and step 7 both should be able to drive the robot

