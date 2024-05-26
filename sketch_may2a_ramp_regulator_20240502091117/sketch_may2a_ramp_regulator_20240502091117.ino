#include <Arduino.h>

// Define pin numbers for LEDs and timeout values
#define GREEN_LED 2
#define RED_LED 3
#define TOR_TIMEOUT 600000
#define TIMEOUT_PERIOD 5000  // Timeout period in milliseconds

// Variables to manage TOR and input handling
volatile unsigned long lastTORTime = 0;
volatile unsigned long tor = 3000;  // Default value for TOR
volatile unsigned long GREEN_DURATION = 3000;  // Default value for TOG
volatile int inputTOR = 0;
volatile bool inputReceived = false;
String inputString = "";  // String to store incoming serial data
volatile unsigned long serialEvent_startTime;  // Record the start time of serialEvent
volatile bool serialEvent_boolean = false;     // Flag to track if serialEvent is active

// Function prototypes
void checkTorTimeout();
void handleInputTOR();
void switchLEDState();
void resetTor();
void processCommand();

// Setup function runs once at the beginning
void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(GREEN_LED, OUTPUT);  // Set pin modes
  pinMode(RED_LED, OUTPUT);
  Serial.println("Enter Tor:");  // Prompt user for input
  attachInterrupt(digitalPinToInterrupt(0), serialEvent, FALLING);  // Attach interrupt for serial input
}

// Main loop function
void loop() {
  // Check for TOR timeout, handle input, and manage LED states
  checkTorTimeout();
  handleInputTOR();
  switchLEDState();

  // Timeout handling for serial input
  if (millis() - serialEvent_startTime > TIMEOUT_PERIOD && serialEvent_boolean) {
    inputString = "";  // Reset input buffer
    Serial.println("Invalid input timeout. Resetting input buffer to default value.");  // Print timeout message
    serialEvent_boolean = false;  // Reset serial event flag
  }
}

// Function to check for TOR timeout
void checkTorTimeout() {
  static bool timeoutPrinted = false;  // Flag to track if timeout message has been printed
  
  // Check if TOR timeout has occurred
  if (millis() - lastTORTime >= TOR_TIMEOUT) {
    if (!timeoutPrinted) {
      resetTor();  // Reset TOR to default value
      Serial.println("TOR input timeout. Resetting TOR to default value.");  // Print timeout message
      timeoutPrinted = true;  // Set flag to true to indicate message has been printed
    }
  } else {
    timeoutPrinted = false;  // Reset flag if timeout condition is not met
  }
}

// Function to handle incoming TOR input
void handleInputTOR() {
  if (inputReceived) {
    // Check if the received TOR value is within a valid range
    if (inputTOR >= 0 && inputTOR <= 999) {
      // Convert the received TOR value to milliseconds
      tor = inputTOR * 1000;
      lastTORTime = millis();  // Update last TOR time
      Serial.print("Received TOR input: ");
      Serial.println(inputTOR);
    } else {
      // Print error message for invalid TOR value and reset TOR to default
      Serial.println("Invalid TOR value. Resetting TOR to default.");
      inputTOR = 3;  // Default TOR value
      tor = 3000;  // Default TOR value in milliseconds
    }
    Serial.println("Enter Tor:");  // Prompt user for input
    inputReceived = false;  // Reset input flag
  }
}

// Function to switch LED states based on TOR and duration
void switchLEDState() {
  static enum { GREEN_ON, RED_ON } state = GREEN_ON;  // State variable to track LED states
  static unsigned long lastTime = 0;  // Variable to track time for LED switching

  switch (state) {
    case GREEN_ON:
      // Switch to red LED after green duration
      if (millis() - lastTime >= GREEN_DURATION) {
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(RED_LED, HIGH);
        lastTime = millis();  // Update last LED switch time
        state = RED_ON;  // Change state to red LED
      } else {
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(RED_LED, LOW);
      }
      break;
      
    case RED_ON:
      // Switch to green LED after TOR duration
      if (millis() - lastTime >= tor) {
        digitalWrite(RED_LED, LOW);
        lastTime = millis();  // Update last LED switch time
        state = GREEN_ON;  // Change state to green LED
      } else {
        digitalWrite(RED_LED, HIGH);
      }
      break;
  }
}

// Function to reset TOR to default value
void resetTor() {
  tor = 3000;  // Default TOR value
  GREEN_DURATION = 3000; // Reset TOG to default value
}

// Function to handle incoming serial data
void serialEvent() {
  serialEvent_startTime = millis();  // Record the start time
  serialEvent_boolean = true;
  Serial.println(millis());

  while (Serial.available() > 0) {
    char incomingChar = Serial.read();  // Read incoming character
    
    // Print received character to serial monitor
    Serial.print("Received character: ");
    Serial.println(incomingChar);
    
    // Process incoming command
    if (incomingChar == ':') {
      processCommand();  // Process command once ":" is detected
      break;  // Exit the loop once command is processed
    } else {
      inputString += incomingChar;  // Accumulate characters until ":" is encountered
    }
  }
}

// Function to process incoming commands
void processCommand() {
  if (inputString.startsWith("SET TOR")) {
    // Process SET TOR command
    String torValue = "";  // String to store TOR value
    char inputChar;  // Variable to store incoming character
    
    // Read TOR value characters
    while (Serial.available() > 0) {
      inputChar = Serial.read();  // Read incoming character
      Serial.print("Received inputTOR: ");
      Serial.println(inputChar);  // Print received character
      
      // Check if input is not a newline character
      if (inputChar != '\n') {
        torValue += inputChar;  // Append character to TOR value string
      } else {
        inputString="";  // Clear input string after processing TOR value
        break;
      }
    }
    
    // Convert TOR string to integer
    inputTOR = torValue.toInt();
    
    Serial.println("Received command is: set TOR");
    Serial.print("TOR value: ");
    Serial.println(inputTOR);
    
    // Check if TOR value is within valid range
    if (inputTOR < 0 || inputTOR > 999) {
      Serial.println("Invalid TOR value. Resetting TOR to default.");
      inputTOR = 3;  // Default TOR value
      resetTor();  // Reset TOR to default value
      // Clear serial buffer
      while (Serial.available() > 0) {
        Serial.read();  // Clear any remaining characters in the buffer
      }
    }
    
    inputReceived = true;  // Set input flag to indicate TOR received
  } else if (inputString.startsWith("SET TOG")) {
    // Process SET TOG command
    String togValue = "";  // String to store TOG value
    char inputChar;  // Variable to store incoming character
    
    // Read TOG value characters
    while (Serial.available() > 0) {
      inputChar = Serial.read();  // Read incoming character
      Serial.print("Received inputTOG: ");
      Serial.println(inputChar);  // Print received character
      
      // Check if input is not a newline character
      if (inputChar != '\n') {
        togValue += inputChar;  // Append character to TOG value string
      } else {
        inputString="";  // Clear input string after processing TOG value
        break;
      }
    }
    
    // Convert TOG string to integer
    unsigned long togMilliseconds = togValue.toInt() * 1000;  // Convert TOG to milliseconds
    GREEN_DURATION = togMilliseconds;  // Update GREEN_DURATION with TOG value
    
    Serial.println("Received command is: set TOG");
    Serial.print("TOG value (milliseconds): ");
    Serial.println(togMilliseconds);
    
    // Check if TOG value is within valid range
    if (togMilliseconds < 0) {
      Serial.println("Invalid TOG value. Resetting TOG to default.");
      GREEN_DURATION = 3000;  // Default TOG value
    }
    
    inputReceived = true;  // Set input flag to indicate TOG received
   } else if (inputString.startsWith("RESET")) {
    // Process RESET command
    resetTor();  // Reset TOR to default value
    Serial.println("Received command is: RESET");
    Serial.println("TOR and TOG reset to default value.");
    
    // Clear serial buffer
    while (Serial.available() > 0) {
      Serial.read();  // Clear any remaining characters in the buffer
    }
    
    inputString = "";  // Reset input string after processing reset command
  } else {
    // Invalid command, reset and clear buffer
    Serial.println("Invalid command. Resetting TOR and TOG and clearing buffer.");
    resetTor();  // Reset TOR to default value
    GREEN_DURATION = 3000;  // Reset TOG to default value
    // Clear serial buffer
    while (Serial.available() > 0) {
      Serial.read();  // Clear any remaining characters in the buffer
    }
    inputString = "";  // Reset input string
  }
}
