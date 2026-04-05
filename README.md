🚗 Parking Management System in C
📌 Overview

The Parking Management System is a command-line application developed in the C programming language that simulates real-time vehicle parking operations. The system efficiently manages parking slots, validates vehicle details, prevents duplicate entries, calculates parking duration, and generates billing based on time spent.

Traditional parking systems rely heavily on manual tracking, which is error-prone and inefficient. This project introduces a structured, programmatic approach using core C concepts like structures, arrays, and modular programming to automate parking operations.

The application allows users to park vehicles, remove them, view parking status, and generate bills dynamically.

✨ Features
🚘 Vehicle Parking
Allows users to park a vehicle with:
Vehicle Number (Plate)
Vehicle Type
Owner Name
Automatically assigns an available parking slot
🔍 Validation System
Ensures proper vehicle number format
Prevents duplicate vehicle entries
Validates vehicle type input
📊 Parking Slot Management
Supports up to 10 parking slots
Tracks occupied and available slots
Displays real-time parking status
⏱ Time-Based Billing
Records entry time using system clock
Calculates parking duration during exit
Charges based on hourly rate
Minimum billing duration is 1 hour
🧾 Billing System
Generates bill with:
Vehicle number
Parking duration
Total amount
🚫 Duplicate Detection
Prevents the same vehicle from being parked multiple times
🧠 System Concept

The system simulates a real-world parking environment using structured data handling and modular design. Each vehicle is tracked with its details, assigned slot, and entry time. The system ensures consistency through validation checks and efficient slot management.

🏗 Implementation Approach
Vehicles are stored using structured data types
Parking slots are managed using arrays
Time functions are used to track entry and exit duration
Modular functions handle parking, removal, validation, and display
⚙ Supported Operations
Park Vehicle
Remove Vehicle and Generate Bill
View Parking Slot Status
Exit Application
📋 Program Workflow
User selects an option from the menu
If parking a vehicle:
Enter vehicle details
System validates input
Assigns available slot
If removing a vehicle:
Enter vehicle number
System calculates duration and bill
Displays output and returns to menu
⚠ Special Case Handling
Input Validation
Rejects invalid vehicle numbers
Ensures only valid characters are used
Duplicate Handling
Prevents duplicate vehicle entries
Billing Edge Cases
Minimum charge applied for short duration
Handles vehicle not found scenarios
Prevents invalid slot operations
🛠 Technologies Used
C Programming
Structures and Arrays
Pointers
Time Handling
Modular Programming
CLI-Based System Design
📂 Project Structure
Main program file
Parking module
Vehicle removal module
Slot viewing module
Validation module
Header file
▶️ How to Run
Compile all source files using a C compiler
Execute the generated program
Interact using the menu-driven interface
🎯 Applications
Office parking systems
Hospital parking management
College and campus parking
Shopping mall parking
Small-scale automated parking setups
🎓 Learning Outcomes
Designing real-world systems using C
Managing structured data efficiently
Implementing time-based logic
Handling user input and validation
Building modular applications
🚀 Future Improvements
File handling for data persistence
Graphical user interface
Mobile or web integration
RFID-based vehicle identification
IoT-based smart parking system
Dynamic slot scalability
⚡ Limitations
Fixed number of parking slots
No persistent storage
Command-line interface only
Limited input flexibility
👨‍💻 Author

Pranav Prasad
