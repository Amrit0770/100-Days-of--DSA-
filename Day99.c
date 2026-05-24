/*
Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to store car details
struct Car {
    int position;
    int speed;
};

// Compare function to sort cars by position in descending order
int compare(const void *a, const void *b) {
    struct Car *c1 = (struct Car *)a;
    struct Car *c2 = (struct Car *)b;

    return c2->position - c1->position;
}

// Function to calculate number of car fleets
int carFleet(int target, int position[], int speed[], int n) {
    struct Car cars[n];

    // Store car details
    for(int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Sort cars by position descending
    qsort(cars, n, sizeof(struct Car), compare);

    int fleets = 0;
    double maxTime = 0;

    // Traverse cars from nearest to target
    for(int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        // New fleet formed
        if(time > maxTime) {
            fleets++;
            maxTime = time;
        }
    }

    return fleets;
}

int main() {
    int target, n;

    // Input target distance and number of cars
    printf("Enter target distance and number of cars: ");
    scanf("%d %d", &target, &n);

    int position[n], speed[n];

    // Input car positions
    printf("Enter positions of cars:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }

    // Input car speeds
    printf("Enter speeds of cars:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &speed[i]);
    }

    // Calculate number of fleets
    int result = carFleet(target, position, speed, n);

    // Print result
    printf("Number of car fleets: %d\n", result);

    return 0;
}
