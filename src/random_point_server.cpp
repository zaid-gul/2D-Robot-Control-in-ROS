#include "ros/ros.h"
#include "assignment1/target.h"
#include <math.h>


// function for generating a random number between 2 numbers [M,N]
double randMToN(double M, double N) 
{ 
	return M + (rand() / ( RAND_MAX / (N-M) ) ) ;
 }


//This function randomly generates a number in the interval (-6,6) for the values of x and y
bool randTarget (assignment1::target::Request &req, assignment1::target::Response &res){
   res.x = randMToN(-6.0, 6.0);
   res.y = randMToN(-6.0, 6.0);
   return true;
}

int main(int argc, char **argv)
{
   // Initialize the node, setup the NodeHandle for handling the communication with the ROS system
   ros::init(argc, argv, "random_point_server");
   ros::NodeHandle n;
   ros::ServiceServer service= n.advertiseService("/random_coordinates", randTarget);
   ros::spin();

   return 0;
}
