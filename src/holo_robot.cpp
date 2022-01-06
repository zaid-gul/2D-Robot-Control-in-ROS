#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include "assignment1/target.h"

//Global Variables
ros::Publisher pub; 
ros::ServiceClient client; 
assignment1::target random_position; 
int k = 2; 
float x_position;
float y_position;
geometry_msgs::Twist vel;

// Function for position
void positionCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
  // read robot postion (x,y)
  x_position = msg->pose.pose.position.x; 
  y_position = msg->pose.pose.position.y;
	
// Check the difference between the target and robot position
// if the diffenrence was less than 0.1 target is reached!
// then receive a new target position

if(abs(random_position.response.x - x_position) < 0.1 && abs(random_position.response.y - y_position) < 0.1 )
 {	
	client.call(random_position); 
	ROS_INFO("Random coordinates of Robot: [%f, %f]", random_position.response.x , random_position.response.y);
 }
  
  // set linear velocities 
  vel.linear.x = k*(random_position.response.x - x_position);
  vel.linear.y = k*(random_position.response.y - y_position);
  
  // publish velocity values
  pub.publish(vel);

}


int main(int argc, char **argv)
{
  // Initialize the node, setup the NodeHandle for handling the communication with the ROS
  // system
  ros::init(argc, argv, "holo_robot");
  ros::NodeHandle n; 

  client = n.serviceClient<assignment1::target>("/random_coordinates");
  client.call(random_position);

  ros::Subscriber pose_sub = n.subscribe("/odom", 1000, positionCallback);

  // define the publisher to publish robot Twist (speed values)
  pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
  
  ros::spin();

  return 0;
}
