# Parking Management System

A terminal-based **Parking Management System** written in **C** that simulates core parking lot operations such as vehicle entry, vehicle exit, slot allocation, slot release, slot availability monitoring, and parking bill generation.

This project is designed as a modular C application and is suitable for demonstrating:

- structured programming in C
- menu-driven terminal applications
- modular file organization using header/source files
- validation handling
- arrays of structures
- basic time-based billing logic
- parking slot management workflows

---

## Overview

The system manages a parking lot with a fixed number of slots and supports multiple vehicle categories. When a vehicle enters, the application validates the details, checks for duplicates, allocates the next free slot, and stores the entry time. When the vehicle exits, the system calculates the fare based on parked duration and vehicle type, releases the occupied slot, and prints a formatted bill.

The project currently runs entirely in memory during execution and uses a clean function-based modular structure split across multiple C source files.

---

## Features

### Core Features

- Park a vehicle through a menu-driven interface
- Exit a parked vehicle using the vehicle plate number
- Check live parking slot availability
- Auto-assign the next available free slot
- Prevent duplicate parking entries for the same vehicle plate
- Validate vehicle plate format
- Validate owner name format
- Validate supported vehicle types
- Record entry and exit timestamps using `time(NULL)`
- Calculate parking charges based on hourly rates
- Generate a formatted parking bill on vehicle exit
- Release the slot automatically after exit
- Display a colorized terminal UI using ANSI escape sequences

### Supported Vehicle Types

- Car
- Bike
- Auto
- Minibus

### Billing Support

Different hourly rates are applied depending on vehicle type:

- **Bike** → 10
- **Auto** → 25
- **Car** → 40
- **Minibus** → 70

Minimum billing is **1 hour** even if the actual duration is less than 1 hour.

---

## Functional Workflow

### 1. Park Vehicle

When the user selects **Park a Vehicle**, the system:

1. asks whether the user wants to continue parking
2. accepts vehicle plate number
3. validates plate length and characters
4. checks whether the vehicle is already parked
5. accepts owner name
6. validates the owner name
7. accepts vehicle type
8. validates the vehicle type
9. allocates the next available slot
10. stores entry time and vehicle details
11. confirms successful parking with slot number

### 2. Exit Vehicle

When the user selects **Exit a Vehicle**, the system:

1. asks for the vehicle plate number
2. searches the parked vehicle list
3. captures exit time
4. calculates fare based on time duration and vehicle type
5. releases the occupied slot
6. prints a complete parking bill

### 3. Check Slot Availability

When the user selects **Check Slot Availability**, the system prints a visual slot map:

- `[   ]` = vacant
- `[ X ]` = occupied

The current implementation supports **10 parking slots**.

---

## Project Structure

```text
Parking_Management_System/
├── main.c
├── main.h
├── vehicle_park.c
├── vehicle_exit.c
├── validations.c
├── slot.c
├── park_rate.c
├── bill.c
└── a.out
```

### File Responsibilities

#### `main.c`
- application entry point
- displays the main menu
- routes user input to the correct service function

#### `main.h`
- macro definitions
- structure declarations
- extern declarations for global arrays
- function prototypes

#### `vehicle_park.c`
- handles vehicle parking workflow
- collects input
- validates data
- allocates slot
- stores vehicle details and entry time

#### `vehicle_exit.c`
- handles vehicle exit workflow
- searches parked vehicle
- records exit time
- calculates fare
- releases parking slot
- prints parking bill

#### `validations.c`
- validates vehicle plate
- validates owner name
- validates vehicle type
- checks duplicate vehicle entries
- finds a vehicle by plate number

#### `slot.c`
- assigns next free slot
- releases slot on exit
- displays slot occupancy status

#### `park_rate.c`
- returns hourly rate based on vehicle type
- calculates total fare based on duration

#### `bill.c`
- prints detailed parking receipt including:
  - slot ID
  - plate number
  - owner name
  - vehicle type
  - entry time
  - exit time
  - duration
  - total amount

---

## Data Structures Used

### `Vehicle`
Stores all vehicle-related parking information:

- `slot_id`
- `plate`
- `owner`
- `vehicle_type`
- `entry_time`
- `exit_time`

### `ParkingSlot`
Tracks each slot’s current occupancy state:

- `slot_id`
- `is_occupied`
- `plate`

---

## Validation Rules

### Vehicle Plate Validation
- must be exactly **9 characters**
- must contain only **alphanumeric characters**

### Owner Name Validation
- currently accepts only **alphabetic characters**
- spaces and special characters are rejected in validation logic

### Vehicle Type Validation
Only the following are accepted exactly as written:

- `Car`
- `Bike`
- `Auto`
- `Minibus`

---

## Constants and Limits

Defined in `main.h`:

- `MAX_SLOTS = 10`
- `MAX_VEHICLES = 10`
- `SUCCESS = 1`
- `FAILURE = -1`
- `FULL = -2`
- `EXIT = 0`

---

## Build and Run

### Compile

```bash
gcc main.c vehicle_park.c vehicle_exit.c validations.c slot.c park_rate.c bill.c -o parking_management_system
```

Or simply:

```bash
gcc *.c -o parking_management_system
```

### Run

```bash
./parking_management_system
```

---

## Sample Menu

```text
1. Park a Vehicle
2. Exit a Vehicle
3. Check Slot Availability
4. Exit
```

---

## Example Use Case

### Vehicle Entry
- Plate: `KL07AB123`
- Owner: `Pranav`
- Type: `Car`
- Allocated Slot: `1`

### Vehicle Exit
On exit, the system:
- reads the exit time
- computes parked duration
- multiplies by hourly rate
- prints the bill

---

## Technical Highlights

- Written in pure C
- Modular multi-file implementation
- Uses arrays of structures for record storage
- Uses `time.h` for tracking duration
- Uses string handling and validation logic
- Uses terminal color formatting for better UX
- Simple enough for learning, extendable enough for mini-project enhancement

---

## Current Limitations

Based on the uploaded source files, the current implementation has some practical limitations:

- data is **not persistent**; all records are lost when the program exits
- maximum vehicle records are limited to **10**
- owner name validation currently rejects names with spaces even though input allows full-line entry
- exited vehicles remain in the `vehicles` array, so the same plate may still be treated as duplicate later unless logic is extended
- `slot_id` field inside `ParkingSlot` is declared but not explicitly initialized or used in logic
- plate validation is generic alphanumeric only and does not enforce a regional registration pattern
- vehicle type comparison is case-sensitive (`Car` works, `car` does not)
- no admin login, reports, search history, or revenue summary
- no file handling or database storage yet

---

## Suggested Future Enhancements

This project has a strong base for extension. Good next upgrades would be:

- add **file handling** for persistent parking records
- support **re-entry** of vehicles after exit by marking active/inactive status
- allow **owner names with spaces**
- make vehicle type matching **case-insensitive**
- store **slot-wise history** and daily logs
- add **date/time formatted reports**
- generate **daily / weekly revenue summaries**
- support **different parking zones**
- add **admin dashboard**
- include **search, update, and delete** operations
- add **fine-grained billing** using minutes instead of full-hour rounding only
- create a **Makefile** for easier compilation
- remove compiled binaries like `a.out` from source control and add a proper `.gitignore`

---

## Learning Outcomes

This project is useful for learning and demonstrating:

- C program structure across multiple files
- header file usage
- function prototypes and extern variables
- array and structure handling
- string validation
- menu-driven control flow
- time-based calculations
- basic real-world system design in C

---

## Suitable For

- C mini project
- academic submission
- embedded / systems programming practice
- beginner-level DSA and structured programming practice
- resume / GitHub project portfolio improvement

---

## Recommended GitHub Improvements

To make the repository more professional, add:

- `README.md`
- `.gitignore`
- sample screenshots or terminal output images
- project flowchart
- module diagram
- future scope section
- license file

A basic `.gitignore` for this repo could be:

```gitignore
*.out
*.o
*.exe
```

---

## Conclusion

The **Parking Management System** is a clean and practical C project that demonstrates how real-world parking workflows can be modeled using structures, arrays, validation logic, slot management, and time-based billing. It is a solid beginner-to-intermediate systems programming project and a good foundation for building a more advanced parking automation application.

---

## Author

**Pranav**

If you are using this project for GitHub, adding screenshots, a project demo GIF, and persistent file storage will make it significantly stronger for recruiters and reviewers.
