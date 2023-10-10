# HAND MOTION CONTROLLED ROBOTIC ARM

This project demonstrates the integration of the MPU6050 gyroscope and accelerometer sensor with a microcontroller to control servo motors based on the sensor readings. 

It also includes the use of flex sensors to further control the movements.

# Table of Contents

**Overview**

**Components**

**How to Use**

**Code Explanation**

# Overview

The MPU6050 sensor is a popular accelerometer and gyroscope combination sensor often used in various projects. 

In this project, we utilize the MPU6050 sensor to measure angles in different axes and control servo motors accordingly.

Additionally, flex sensors are employed to add an extra layer of control, enabling the user to manipulate the servo motors based on finger flexion.

# Components

**-STM 32 Nucleo F401RE**

**-MPU6050 sensor**

**-Servo motors**

**-Flex sensors**

**-Resistors**

**-LED**

**-Breadboard**

**-Connecting wires**

# How to Use

Connect the MPU6050 sensor, servo motors, flex sensors, and other components to the STM32 NUCLEO F401RE board following the specified pin connections in the code.

Upload the provided codes to the STM32 board.

Open the serial monitor to observe the sensor readings and adjust the servo motors accordingly.

Control the servo motors using flex sensors and observe how the movements are affected.

# Code Explanation

The provided code (`MPU6050_A.h`) includes a class for interfacing with the MPU6050 sensor and functions to calculate offsets, set configurations, and update sensor data. 

It also contains control logic for the servo motors based on the sensor readings and flex sensor inputs.

The code (`MPU6050_A.cpp`) defines the implementation of the MPU6050 class and related utility functions for interfacing with an MPU6050 accelerometer and gyroscope sensor using a microcontroller.

The MPU6050 sensor provides information about acceleration, gyroscope values, and temperature.

This code written (`stmnucle_mpu_with_flex_sensor.ino`) in C++ involves interfacing with various sensors and controlling servo motors based on sensor readings. 

The code uses an MPU6050 accelerometer and gyroscope, two flex sensors, and five servo motors.

# Project Report

For a more comprehensive understanding of this project, including detailed circuit diagrams, component requirements, and in-depth explanations, please refer to the `printrep.pdf`.
