#include <iostream>
#include "ros/ros.h"
#include "std_msgs/Float64.h"

int main(int argc, char **argv) {
  std::cout << "Robot Controller runnning!\n";
  std::cout << "[00]: Stop Base; [01]: Move Base CW; [02]: Move Base CCW \n";
  std::cout << "[10]: Stop First joint; [11]: Move First joint CW; [12]: Move First joint CCW \n";
  std::cout << "[20]: Stop Second joint; [21]: Move Second joint CW; [22]: Move Second joint CCW \n";

  ros::init(argc, argv, "Arm_controller_node");
  ros::NodeHandle n;
  ros::Publisher basePub = n.advertise<std_msgs::Float64>("base_controller/command", 1000);
  ros::Publisher l1_Pub = n.advertise<std_msgs::Float64>("link_1_controller/command", 1000);
  ros::Publisher l2_Pub = n.advertise<std_msgs::Float64>("link_2_controller/command", 1000);

  while(ros::ok()){
    char in1, in2;
    std::cout << "Please enter a value: ";
    std::cin >> in1 >> in2;
    std::cout << "\n";

    std_msgs::Float64 speedMsg;

    switch(in2){

      case '0':
        speedMsg.data = 0.0;
        break;

      case '1':
        speedMsg.data = 1.0;
        break;
      
      case '2':
        speedMsg.data = -1.0;
        break;

      default:
        std::cout <<"PLEASE ENTER A VALID VALUE! \n";
        std::cout << "\n";
        break;

    }

    switch(in1){

      case '0':
        basePub.publish(speedMsg);
        break;

      case '1':
        l1_Pub.publish(speedMsg);
        break;

      case '2':
        l2_Pub.publish(speedMsg);
        break;
      
      default:
        std::cout <<"PLEASE ENTER A VALID VALUE! \n";
        std::cout << "\n";
        break;
        
    }

  }

  return 0;
}
