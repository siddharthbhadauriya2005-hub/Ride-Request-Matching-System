#include <stdio.h>
#include <string.h>

#define MAX_DRIVERS 50
#define NAME_LEN 50
#define PLACE_LEN 80

typedef struct {
    int id;
    char name[NAME_LEN];
    char vehicle[NAME_LEN];
    char location[PLACE_LEN];
    float distanceFromPickup;
    int available;
} Driver;

typedef struct {
    int rideId;
    char passenger[NAME_LEN];
    char pickup[PLACE_LEN];
    char destination[PLACE_LEN];
    float tripDistance;
    float fare;
    int driverId;
} Ride;

Driver drivers[MAX_DRIVERS];
int driverCount = 0;
int nextRideId = 1;

void readLine(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

void addDriver(void) {
    if (driverCount >= MAX_DRIVERS) {
        printf("\nDriver list is full!\n");
        return;
    }

    Driver d;
    d.id = driverCount + 1;
    printf("\n--- Add New Driver ---\n");
    readLine("Driver name: ", d.name, NAME_LEN);
    readLine("Vehicle (e.g. Sedan, Bike): ", d.vehicle, NAME_LEN);
    readLine("Current location: ", d.location, PLACE_LEN);

    printf("Distance from your sample pickup point (km): ");
    if (scanf("%f", &d.distanceFromPickup) != 1 || d.distanceFromPickup < 0) {
        printf("Invalid distance. Driver was not added.\n");
        while (getchar() != '\n');
        return;
    }
    getchar();

    d.available = 1;
    drivers[driverCount++] = d;
    printf("\nDriver added successfully! Driver ID: %d\n", d.id);
}

void showDrivers(void) {
    int i;
    printf("\n================ AVAILABLE DRIVERS ================\n");
    if (driverCount == 0) {
        printf("No drivers added yet.\n");
        return;
    }

    printf("%-5s %-20s %-15s %-20s %-10s\n",
           "ID", "NAME", "VEHICLE", "LOCATION", "STATUS");
    for (i = 0; i < driverCount; i++) {
        printf("%-5d %-20s %-15s %-20s %-10s\n",
               drivers[i].id, drivers[i].name, drivers[i].vehicle,
               drivers[i].location,
               drivers[i].available ? "Available" : "Busy");
    }
}

void bookRide(void) {
    Ride r;
    int i, bestIndex = -1;
    float nearest = 999999.0f;

    if (driverCount == 0) {
        printf("\nPlease add at least one driver first.\n");
        return;
    }

    printf("\n--- Book a Ride ---\n");
    readLine("Passenger name: ", r.passenger, NAME_LEN);
    readLine("Pickup location: ", r.pickup, PLACE_LEN);
    readLine("Destination: ", r.destination, PLACE_LEN);

    printf("Trip distance (km): ");
    if (scanf("%f", &r.tripDistance) != 1 || r.tripDistance <= 0) {
        printf("Invalid trip distance.\n");
        while (getchar() != '\n');
        return;
    }
    getchar();

    for (i = 0; i < driverCount; i++) {
        if (drivers[i].available &&
            drivers[i].distanceFromPickup < nearest) {
            nearest = drivers[i].distanceFromPickup;
            bestIndex = i;
        }
    }

    if (bestIndex == -1) {
        printf("\nSorry! No drivers are currently available.\n");
        return;
    }

    r.rideId = nextRideId++;
    r.driverId = drivers[bestIndex].id;
    r.fare = r.tripDistance * 12.0f;
    drivers[bestIndex].available = 0;

    printf("\n============= RIDE CONFIRMED =============\n");
    printf("Ride ID          : %d\n", r.rideId);
    printf("Passenger        : %s\n", r.passenger);
    printf("Pickup           : %s\n", r.pickup);
    printf("Destination      : %s\n", r.destination);
    printf("Driver           : %s\n", drivers[bestIndex].name);
    printf("Vehicle          : %s\n", drivers[bestIndex].vehicle);
    printf("Driver distance  : %.1f km from pickup\n", nearest);
    printf("Trip distance    : %.1f km\n", r.tripDistance);
    printf("Estimated fare   : Rs. %.2f\n", r.fare);
    printf("==========================================\n");
}

int main(void) {
    int choice;

    /* Sample drivers make the project easy to demonstrate. */
    drivers[0] = (Driver){1, "Aman", "Bike", "City Centre", 2.0f, 1};
    drivers[1] = (Driver){2, "Rahul", "Sedan", "Bus Stand", 4.5f, 1};
    drivers[2] = (Driver){3, "Simran", "Auto", "Market Road", 1.2f, 1};
    driverCount = 3;

    do {
        printf("\n============================================\n");
        printf("       RIDE REQUEST MATCHING SYSTEM\n");
        printf("============================================\n");
        printf("1. Add Driver\n");
        printf("2. View Drivers\n");
        printf("3. Book a Ride\n");
        printf("4. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();

        switch (choice) {
            case 1: addDriver(); break;
            case 2: showDrivers(); break;
            case 3: bookRide(); break;
            case 4: printf("\nThank you for using the Ride Request Matching System!\n"); break;
            default: printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
