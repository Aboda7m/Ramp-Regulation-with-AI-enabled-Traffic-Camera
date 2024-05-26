# README: Reproducing the Ramp Regulation Simulation

## Overview
This guide provides detailed instructions on how to reproduce the ramp regulation simulation scenario using the PTV Vissim traffic simulator. The simulation involves adjusting the Time of Red (TOR) for a traffic light signal to manage ramp congestion levels effectively.

## Prerequisites
Before you start, ensure you have the following:
- PTV Vissim installed on your computer

## Simulation Setup

### Step 1: Create the Traffic Model
1. **Open PTV Vissim**: Launch PTV Vissim on your computer.
2. **Create a New Network**: Go to `File` > `New` to create a new traffic network.
3. **Draw the Freeway**:
   - Use the `Links` tool to create a 3-lane freeway.
   - Set the length of the freeway link according to your simulation requirements.
4. **Draw the Ramp**:
   - Use the `Links` tool to create a single-lane ramp that merges into the freeway.
   - Connect the ramp to the freeway at the desired merging point.

### Step 2: Set Up Traffic Demand
1. **Define Traffic Inputs**:
   - Go to `Traffic Inputs` and create traffic inputs for both the freeway and the ramp.
   - Set the traffic input rates (vehicles per hour) as per your simulation scenario.
2. **Set Up Vehicle Routes**:
   - Define the desired vehicle routes to ensure vehicles from the ramp merge into the freeway.
   - Adjust the route decisions and priorities to simulate realistic traffic behavior.

### Step 3: Install Traffic Light Signal
1. **Add Traffic Light Signal**:
   - Place a traffic light signal at the stop bar near the ramp-to-freeway junction.
2. **Configure Signal Control**:
   - Go to `Signal Controllers` and add a new signal controller.
   - Define the signal phases for the ramp traffic light, focusing on the Time of Red (TOR) adjustments.

### Step 4: Define Time of Red (TOR) Values
1. **Configure Traffic Program**:
   - **Step 1**: After adding the traffic light, go to the `Signal Controllers` tab.
     - Inside this tab, you will find information like the name of the ramp regulator, the ID of the program it is running, and the config file path. For example, the ID might be 1.
   - **Step 2**: Go to your signal controller and double-click the `supplyFile1` field.
   - **Step 3**: A signal controller window will open; click on `Edit Controller Data` inside it.
   - **Step 4**: A Vissig window will open; click on `Signal Program`.
   - **Step 5**: Create multiple programs, each with a different TOR value.
   - **Step 6**: Once you finish, click on `Daily Signal Program List`.
   - **Step 7**: Create a new list with an ID number you choose and remember it (example ID = 1000).
   - **Step 8**: In this list, link each different TOR value program we created into hourly slots.
   - **Step 9**: After you finish, click save and close all windows.
   - **Step 10**: Now back in the `Signal Controllers` tab, go to the `Program ID` field and change it from the current value to the value we created for the list (example ID = 1000).
   - **Step 11**: Now the traffic light is linked to the program list per hour, and the simulation can be started.

### Step 5: Run the Simulation
1. **Simulation Runtime**:
   - Duration: 600 minutes (10 hours)
   - Warm-up Period: 5 minutes
2. **Start Simulation**:
   - Configure the simulation runtime parameters.
   - Start the simulation and observe traffic flow, focusing on the impact of different TOR values on congestion levels.
3. **Record Results**:
   - Collect data on vehicle speeds, queue lengths, and congestion levels before and after applying the TOR adjustments.

### Step 6: Analyze Performance
1. **Evaluate Results**:
   - Compare the initial observed speeds with the speeds after applying the TOR adjustments.
   - Analyze the transition times and effectiveness of the TOR values in reducing congestion.
2. **Present Data**:
   - Create tables and graphs to illustrate the performance results.
   - Summarize the findings in a report or presentation format.

## Example Scenario
Here’s an example of how to set up a specific scenario:

1. **Traffic Input Rates**:
   - Freeway: 2000 vehicles/hour
   - Ramp: 400 vehicles/hour
2. **TOR Values for Each Hour**:
   - Hour 1: 0 seconds
   - Hour 2: 1 second
   - Hour 3: 2 seconds
   - Hour 4: 3 seconds
   - Hour 5: 4 seconds
   - Hour 6: 5 seconds
   - Hour 7: 6 seconds
   - Hour 8: 7 seconds
   - Hour 9: 8 seconds
   - Hour 10: 9 seconds
3. **Simulation Runtime**:
   - Duration: 600 minutes (10 hours)
   - Warm-up Period: 5 minutes

## Additional Notes
- **Saving Your Work**: Regularly save your PTV Vissim files to prevent data loss.
- **Modifying the Model**: Feel free to tweak the traffic inputs, routes, and signal timings to explore different scenarios.

By following these steps, you should be able to reproduce the ramp regulation simulation scenario and analyze the impact of TOR adjustments on traffic congestion. If you encounter any issues or need further assistance, refer to the PTV Vissim user manual or community forums for support.
