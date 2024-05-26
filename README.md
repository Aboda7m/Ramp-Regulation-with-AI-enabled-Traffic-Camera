# Automatic Ramp Regulation System

## Introduction
This repository contains the implementation of an Automatic Ramp Regulation System designed to address traffic congestion issues on freeways. The system utilizes a combination of video processing, congestion estimation, and ramp regulation algorithms to optimize traffic flow and reduce congestion near freeway ramps.

## Contents
- **PTV Vissim Files:** This folder contains simulation files for PTV Vissim, a commercial transportation traffic simulator. These files were used to simulate various traffic scenarios and evaluate the performance of the ramp regulation algorithm.

- **Python Files:**
  - `Video_Processing.py`: Implements vehicle detection and speed calculation using OpenCV and YOLO object detection model.
  - `Network_handler.py`: Facilitates communication with the Arduino microcontroller to control the ramp gate.
  - `Main.py`: Main script for running the Automatic Ramp Regulation System, orchestrating the execution of various modules.

## Usage
To use the Automatic Ramp Regulation System, ensure that you have the required dependencies installed. Then, execute the `Main.py` script to start the system.

## License
This project is licensed under the [MIT License](LICENSE).

## Contact
For inquiries or assistance, please contact:
Abdulmohsen Mutairi, Ph.D.
Assistant Professor
Department of Computer Engineering
College of Computer and Information Sciences
King Saud University
Riyadh, Saudi Arabia
Tel: +966.11.4698208
Email: mutairi@ksu.edu.sa
