#############
# Automatic Ramp Regulation System

## Introduction

This project implements an Automatic Ramp Regulation system designed to address the issue of ramp traffic congestion. It utilizes video processing techniques to analyze freeway traffic, estimate congestion levels, and regulate the traffic flow on the ramp using a traffic light system.

## Usage

```bash
pip install tk pandas opencv-python-headless ultralytics pyserial
```

### Running the Project

1. Download the project files from Google Drive and extract them:

   ```bash
    https://drive.google.com/drive/folders/191eQpfxMc9e565e2T6DUZJM2tEdVbnbd?usp=drive_link
   ```
   After downloading, extract the contents of the downloaded zip file to your desired location on your local machine.

2. Navigate to the project directory:

   ```bash
   cd automatic-ramp-regulation-system
   ```

3. Run the `main.py` file:

   ```bash
   python main.py
   ```

## File Descriptions

- `main.py`: Main script to run the GUI and control the system.
- `Congestion_Estimation.py`: Module for estimating congestion levels.
- `Video_Processing.py`: Module for processing video input.
- `Ramp_Regulater.py`: Module for regulating traffic on the ramp.
- `Network_Handler.py`: Module for handling network communication with the traffic light system.

## Folder Descriptions

- `Excel Simulation Results`: Contains the results of our simulation experiments.
- `PTV Vissim files`: Contains files related to PTV Vissim simulation projects.
- `Ramp Regulation code`: Contains the final code for image processing and the entire project.
- `sketch_may2a_ramp_regulator_20240502091117`: Contains the code for the Arduino ramp regulator.
- `Video Data`: Contains video samples of roads for testing and experimentation. Subfolders include:
  - `Different speeds testing in real life`: Subfolders for testing videos at different speeds (30km/h, 60km/h, 90km/h).
  - `King Fahad North`: Video samples from the north side of King Fahad road.
  - `King Fahad South`: Video samples from the south side of King Fahad road.

## Acknowledgements

This project was developed as part of the course requirements for Our Graduation Project. We would like to thank Dr. Abdulmohsen Mutairi for his guidance and support throughout the development process.

For any inquiries, please contact 438102038@student.ksu.edu.sa and 438103946@student.ksu.edu.sa.
