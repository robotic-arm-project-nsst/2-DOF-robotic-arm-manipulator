# 🤖 Robotic Arm Project

## Overview
Welcome to the **Robotic Arm Project**! This project involves the design and development of a pick and place robotic arm capable of holding a cube with a gripper and placing it in a cup. The project demonstrates the integration of mechanical design, kinematics, and control coding, all brought together through teamwork.

## Objective
The primary goal of this project is to design a robotic arm that can accurately and efficiently hold and move a cube into a designated cup. This involves understanding the mechanics of the arm, calculating the required torque at different points, and programming the arm for precise movements.

## Project Structure
The project consists of several key components:
- **Mechanical Design**: The arm is designed using SolidWorks, including a gripper for handling the cube.
- **Kinematics**: Calculation of the required torque and movement analysis to ensure smooth and accurate operation.
- **Coding**: Implementation of the control code using Arduino to operate the robotic arm.

## Mechanical Design
The robotic arm is composed of two main links, connected by joints, and a gripper at the end for handling objects.

### Components:
- **Joint 1 (MG996 180°)**: 
  - Operating voltage: 4.8 V to 7.2 V
  - Weight: 55 g
- **Joint 2 (MG995 180°)**:
  - Operating voltage: 4.8 V to 7.2 V
  - Weight: 55 g

### Torque Calculation:
The structure analysis was conducted to determine the torque required at each point of action. The robotic arm weighs approximately 200 grams, with the weight imagined to be evenly distributed across the entire length of 46.5 cm. Each servo motor has a mass of 55 grams and experiences a downward force of 0.53 newtons due to gravity.

## Kinematics
Kinematics of the robotic arm were analyzed using trigonometric principles to ensure that the arm movements would be both smooth and accurate.

## Coding
The control code was developed using Arduino, incorporating the following components:
- **Arduino Uno**: The main control unit.
- **Servo Motors**: 
  - MG996R 360°
  - MG996R 180°
  - SG90 180°
- **Ultrasonic Sensor (HC-SR04)**: For distance measurement and object detection.
- **H-Bridge**: For motor control.

## Tools and Technologies
- **SolidWorks**: For mechanical design.
- **Arduino**: For coding and control.
- **Servo Motors**: For movement and control of the robotic arm.
- ![components](https://github.com/user-attachments/assets/a3b4debb-404c-4d96-9be9-f89a88d682ac)



## Demo
Check out the robotic arm in action in the video below:

https://github.com/user-attachments/assets/6552dc5e-120b-44d6-9108-ae83795b305d


## Team Members
This project was completed by a team of dedicated students:
-  jehad moamen mahmoud
-  aliaa mohamed abd elfatah
-  nada hisham abd elgaber
-  mennatallah mohamed mahmoud ali 
-  ahmed mamdouh
-  ahmed mohamed ramadan
-  abdulrahman hisham
-  adham ehab
-  osama gebriel
-  youssef motawea
 
## Contributing
We welcome contributions to enhance the functionality and performance of the robotic arm. Feel free to fork the repository and submit your improvements!

## Contact
For further information or questions, please reach out to [abdulrahmanhishamk@gmail.com](mailto:abdulrahmanhishamk@gmail.com).
