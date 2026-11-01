Ride Request Matching System
Project Type: Mini Project
Programming Language: C
Website Technologies: HTML, CSS, JavaScript
Project Level: Beginner / Academic Demonstration
1. Project Overview
The Ride Request Matching System is a simple ride-booking
application developed as a mini project. Its main purpose is to
demonstrate how a passenger's ride request can be matched with an
available driver.

The project has two parts:
1. C language application: Implements the main ride-management
   logic in a console menu. It can add drivers, display drivers, accept
   ride details, find the nearest available driver from the stored
   sample distances, calculate an estimated fare, confirm a ride, and
   mark the selected driver as busy.
2. Website interface: Provides a modern, responsive front-end
   design. A visitor can enter passenger and trip details and see a
   sample ride confirmation.
Important: In this version, the website JavaScript and the C
program run independently. The website uses its own sample driver
data; it does not send the form to the C program. The C program is the
working console-based implementation of the matching logic. Connecting
the website to the C backend would require an additional server/API
layer.

2. Objectives
- To understand how a basic ride-booking system works.
- To store driver details using structures in C.
- To add and display available drivers.
- To accept passenger, pickup, destination, and trip-distance details.
- To find the nearest available driver using a simple matching
  algorithm.
- To calculate an estimated fare based on trip distance.
- To update a driver's availability after a ride is confirmed.
- To design a user-friendly website using HTML, CSS, and JavaScript.
3. Technologies Used
  Technology           Purpose
  C                    Main console application and ride-matching logic
HTML                 Structure of the website
CSS                  Website layout, colours, spacing, and responsive design
JavaScript           Front-end form validation and demo booking confirmation
GCC                  Compiling the C program
Visual Studio Code   Writing and running project files
Web browser          Viewing the website
4. Folder Structure
Ride_Request_Matching_System/
│
├── ride_system.c
├── index.html
├── style.css
├── script.js
└── README.md
File descriptions
- ride_system.c: Contains the C program, driver data structure,
  menu, driver management, matching algorithm, fare calculation, and
  ride confirmation.
- index.html: Contains the website sections, navigation bar,
  booking form, driver cards, process explanation, and footer.
- style.css: Controls the website's visual design, colours, cards,
  spacing, buttons, and mobile layout.
- script.js: Validates the website form, selects a sample
  available driver for the demo, calculates the sample fare, and
  displays confirmation.
- README.md: Explains the project, setup, features, logic, and
  limitations.
5. How the C Program Works
When the C application starts, it creates three sample drivers:
   Driver ID Name       Vehicle    Current     Distance from Initial
                                   Location    Sample Pickup Status

           1 Aman       Bike       City               2.0 km Available
                                   Centre                    

           2 Rahul      Sedan      Bus Stand          4.5 km Available

           3 Simran     Auto       Market             1.2 km Available
                                   Road                      

These distances are sample values used by the demonstration. They are
not calculated using GPS.

The program then displays a menu:
============================================
       RIDE REQUEST MATCHING SYSTEM
============================================
1. Add Driver
2. View Drivers
3. Book a Ride
4. Exit
--------------------------------------------
Enter your choice:
The user enters a menu number to select an operation.
Option 1: Add Driver
The program asks for:
- Driver name
- Vehicle type
- Current location
- Distance from the sample pickup point
After valid details are entered, the driver is stored in the drivers
array and marked as available.

The program supports a maximum of 50 drivers.
Option 2: View Drivers
The program displays all drivers stored in the array, including their
ID, name, vehicle, location, and current status.

A driver can have one of two statuses:
- Available: The driver can be assigned to a new ride.
- Busy: The driver has already been assigned a ride during the
  current program run.
Option 3: Book a Ride
The passenger enters:
1. Passenger name
2. Pickup location
3. Destination
4. Trip distance in kilometres
The program checks the trip distance. It must be a valid number greater
than zero.

After that, the matching algorithm searches through the driver array.
Option 4: Exit
The program displays a thank-you message and ends.
6. Main Logic and Algorithm
A. Driver storage using a structure
The C program uses a structure named Driver to store related
information about each driver.

Conceptual structure:
typedef struct {
    int id;
    char name[50];
    char vehicle[50];
    char location[80];
    float distanceFromPickup;
    int available;
} Driver;
Explanation:
- id stores the driver's unique number.
- name stores the driver's name.
- vehicle stores the vehicle type.
- location stores the driver's current location as text.
- distanceFromPickup stores the sample distance from the pickup
  point.
- available stores the driver's status: 1 means available and 0
  means busy.
An array named drivers stores multiple driver records:
Driver drivers[50];
B. Nearest available driver matching
The program uses a simple nearest-driver selection algorithm.

Steps:
1. Set bestIndex to -1. This means no driver has been selected yet.
2. Set nearest to a very large value.
3. Visit each driver in the array.
4. Check whether the driver is available.
5. If the driver is available and their distance is smaller than the
   current nearest distance, save that driver's array index.
6. After checking all drivers, assign the selected driver.
7. If no available driver is found, display a message saying no drivers
   are available.
The main C logic is:
int i, bestIndex = -1;
float nearest = 999999.0f;

for (i = 0; i < driverCount; i++) {
    if (drivers[i].available &&
        drivers[i].distanceFromPickup < nearest) {
        nearest = drivers[i].distanceFromPickup;
        bestIndex = i;
    }
}

if (bestIndex == -1) {
    printf("Sorry! No drivers are currently available.\\n");
    return;
}
Example:

Suppose all three sample drivers are available:
- Aman: 2.0 km away
- Rahul: 4.5 km away
- Simran: 1.2 km away
The smallest distance is 1.2 km. Therefore, the program selects Simran.

This is a simplified matching demonstration. It compares the distances
already stored for the drivers; it does not calculate live road distance
or traffic conditions.
C. Fare calculation
The project uses a fixed sample rate of ₹12 per kilometre.

Formula:
Estimated Fare = Trip Distance × Rate per Kilometre
C statement:
r.fare = r.tripDistance * 12.0f;
Example:

If the passenger enters a trip distance of 10 km:
Estimated Fare = 10 × 12
Estimated Fare = ₹120
This is only a demonstration rate, not a live commercial fare.
D. Ride confirmation and driver status update
After selecting a driver, the program:
1. Generates a ride ID.
2. Stores the selected driver's ID in the ride record.
3. Calculates the estimated fare.
4. Changes the selected driver's availability to busy.
5. Displays the ride confirmation details.
The status update is:
drivers[bestIndex].available = 0;
This prevents that same driver from being selected for another ride
during the current program run.
7. Website Working
The website is a front-end demonstration made with HTML, CSS, and
JavaScript.
A. HTML (index.html)
The HTML file creates these sections:
- Navigation bar: Contains the RideOn logo and links to the
  booking, drivers, and process sections.
- Hero section: Introduces the ride-booking service.
- Booking section: Contains input fields for passenger name,
  pickup, destination, and trip distance.
- Driver section: Displays three sample driver cards.
- How it works section: Explains the three basic booking steps.
- Footer: Displays the project name and copyright text.
B. CSS (style.css)
The CSS file controls:
- Page background and colour theme.
- Navigation bar and buttons.
- Hero section and decorative map-style design.
- Booking form and input fields.
- Driver cards and availability labels.
- Spacing, borders, and rounded corners.
- Responsive layout for smaller screens.
C. JavaScript (script.js)
When the user clicks Find my ride, the bookRide() function runs.

It performs these steps:
1. Reads the values entered in the form.
2. Checks that all fields are filled.
3. Checks that the trip distance is greater than zero.
4. Searches the JavaScript sample-driver list for the first available
   driver.
5. Marks that sample driver unavailable.
6. Calculates the fare using the same sample rate of ₹12 per kilometre.
7. Displays the passenger's details, route, matched driver, and
   estimated fare.
The JavaScript driver list is separate from the C driver's array. The
website demo chooses the first available sample driver; the C
application chooses the available driver with the smallest stored pickup
distance.

The escapeHTML() helper safely displays user-entered text in the
confirmation area by escaping HTML-sensitive characters.
8. How to Install and Run the Project
Requirements
- A Windows, Linux, or macOS computer.
- Visual Studio Code (recommended).
- GCC compiler for running the C program.
- A modern web browser such as Chrome, Edge, or Firefox.
A. Run the C program on Windows
Step 1: Extract the project ZIP file.

Step 2: Open Visual Studio Code.

Step 3: Select File → Open Folder and choose the
Ride_Request_Matching_System folder.

Step 4: Open the VS Code terminal using:
Ctrl + `
Step 5: Compile the C file:
gcc ride_system.c -o ride_system
Step 6: Run the program in PowerShell:
.\ride_system.exe
If GCC is not installed, install a GCC toolchain such as MinGW-w64 and
ensure its bin folder is added to the Windows PATH. Restart VS Code
after updating PATH.
B. Run the C program on Linux or macOS
Compile:
gcc ride_system.c -o ride_system
Run:
./ride_system
C. Run the website
Method 1: Directly in a browser
1. Open the project folder.
2. Double-click index.html.
3. The website will open in your default browser.
Method 2: Using VS Code Live Server
1. Open VS Code Extensions using Ctrl + Shift + X.
2. Search for Live Server.
3. Install the extension.
4. Open index.html.
5. Right-click in the editor and select Open with Live Server.
9. Sample C Program Demonstration
Example: View drivers
Enter:
2
The program displays the sample drivers and their availability.
Example: Book a ride
Enter:
3
Passenger name: Priya
Pickup location: College
Destination: Railway Station
Trip distance (km): 10
If all sample drivers are still available, the nearest stored driver is
Simran, whose sample distance is 1.2 km.

Expected confirmation:
============= RIDE CONFIRMED =============
Ride ID          : 1
Passenger        : Priya
Pickup           : College
Destination      : Railway Station
Driver           : Simran
Vehicle          : Auto
Driver distance  : 1.2 km from pickup
Trip distance    : 10.0 km
Estimated fare   : Rs. 120.00
==========================================
The exact result depends on which drivers are available when the ride is
booked.
Example: Try booking again
The selected driver is now marked as busy. The next booking will search
for the nearest remaining available driver.

If all drivers are busy, the program displays:
Sorry! No drivers are currently available.
10. Important Functions Used in C
  Function / Concept   Purpose
  main()             Starts the program and displays the menu
addDriver()        Adds a new driver
showDrivers()      Displays all drivers and their statuses
bookRide()         Accepts a ride request and matches a driver
readLine()         Reads text input safely into a character array
strcspn()          Removes the newline character from text input
scanf()            Reads numeric input
printf()           Displays output
switch             Selects a menu operation
for loop           Checks drivers one by one
if condition       Checks availability and matching conditions
struct             Groups driver information
Array                Stores multiple driver records
11. Limitations of the Current Project
This is an academic prototype, not a live taxi-booking service.
- No GPS or live location tracking is used.
- Driver distances are sample values entered into the program.
- No real-time traffic or road-route calculation is performed.
- Driver and ride data are stored only in memory while the C program
  is running.
- Data is not saved permanently in a database or file.
- The website is not connected to the C program.
- The website uses sample driver data and a simplified demo matching
  process.
- No user login, payment gateway, or live booking service is included.
12. Future Scope
The project can be improved by adding:
1. A database such as MySQL to store drivers and ride history.
2. A C-based web server or API to connect the website with the C
   program.
3. GPS-based driver location and live distance calculation.
4. Passenger and driver login systems.
5. Ride cancellation and ride completion features.
6. A real fare system based on distance, time, and vehicle type.
7. An administrator dashboard to manage drivers and bookings.
8. Persistent driver availability and ride records.
13. Conclusion
The Ride Request Matching System demonstrates the basic working of a
ride-booking application. The C program uses structures, arrays, loops,
conditions, functions, and a nearest-available-driver algorithm to
manage ride requests. It also calculates an estimated fare and updates
driver availability after a ride is confirmed.

The HTML, CSS, and JavaScript website provides a clean and responsive
interface to demonstrate the passenger booking experience.

This project helps learners understand how programming logic can be used
to solve a real-world problem and how a website interface can present
that system to users.
14. Viva Questions and Answers
Q1. What is the Ride Request Matching System?
It is a simple application that matches a passenger's ride request with
an available driver.

Q2. Which programming language is used for the main logic?
C language.

Q3. Why is a structure used in this project?
A structure groups related driver details such as ID, name, vehicle,
location, distance, and availability.

Q4. How does the system select a driver?
It checks all available drivers and selects the one with the smallest
stored distance from the sample pickup point.

Q5. What does available = 1 mean?
It means the driver is available for a new ride.

Q6. What does available = 0 mean?
It means the driver is busy and cannot be assigned another ride in the
current program run.

Q7. How is the estimated fare calculated?
Trip distance is multiplied by ₹12 per kilometre.

Q8. What is the purpose of the bookRide() function?
It accepts passenger and trip details, finds an available driver,
calculates the fare, and displays confirmation.

Q9. What is the role of HTML and CSS?
HTML creates the website structure, and CSS controls its appearance.

Q10. What is the role of JavaScript?
JavaScript validates the website form and displays a sample booking
confirmation.

Q11. Is the website connected to the C program?
No. In this version, they are separate demonstrations. A server/API
layer is needed to connect them.

Q12. Is the distance calculated using GPS?
No. The C program uses sample distances stored for each driver.
Project Name: Ride Request Matching System
Main Language: C
Frontend: HTML, CSS, JavaScript
Purpose: Academic mini project and demonstration