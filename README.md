# Electrical Load Monitoring System (C++)

## Introduction

This project is a simple console-based Electrical Load Monitoring System developed using C++.  
It allows users to register electrical appliances, calculate daily energy consumption, and estimate electricity bills.

The main purpose of this project is to practice file handling, structures, vectors, and menu-driven programming in C++.

---

## Features

- Register new appliances
- View all registered appliances
- Search for an appliance by name
- Calculate total daily energy usage
- Estimate daily and monthly electricity cost
- Save appliance records to a file
- Save billing summary with date and time

---

## How the Program Works

Each appliance has:

- Name
- Power (in watts)
- Hours used per day

The program calculates energy consumption using:

Energy (kWh/day) = (Watts / 1000) × Hours Used Per Day

Then it calculates:

Daily Cost = Total kWh × Tariff  
Monthly Cost = Daily Cost × 30  

All appliance data is stored in a file called:

appliances.txt

Billing summaries are saved in:

billing_summary.txt

---

## Program Menu

1. Register Appliance  
2. View Appliances  
3. Search Appliance  
4. Calculate Bill  
5. Save Appliances  
6. Exit  

The program runs in a loop until the user chooses Exit.

---

## File Structure

- main.cpp  
- appliances.txt  
- billing_summary.txt  
- README.md  

---

## Concepts Used

- Structures (struct Appliance)
- Vectors
- File handling (ifstream and ofstream)
- Input validation
- Loops and conditional statements
- Formatting output using iomanip
- Date and time using ctime

---

## Example

If a fan uses 75 watts for 10 hours:

Energy = (75 / 1000) × 10  
Energy = 0.75 kWh per day  

If tariff is 0.20 per kWh:

Daily Cost = 0.75 × 0.20  
Monthly Cost = Daily Cost × 30  

---

## How to Compile

Using g++:

g++ main.cpp -o monitor  
./monitor  

Or run using any C++ IDE like Code::Blocks or Visual Studio.

---

## Conclusion

This project helped me understand how to:

- Store and retrieve data from files
- Use structures with vectors
- Build a menu-driven system
- Perform basic electricity billing calculations

It is a simple but practical application of C++ programming concepts.