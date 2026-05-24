/*
Problem Statement
Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the 
minimum distance between any two cows is maximized.

This is an optimization problem where binary search on the answer is required.

Input Format
n k
n space-separated integers representing stall positions

Output Format
Print the maximum possible minimum distance between any two cows.

Sample Input
5 3
1 2 8 4 9

Sample Output
3

Explanation
Cows can be placed at positions 1, 4, and 8. The minimum distance between any two cows is 3, which is the maximum possible.
*/
#include <stdio.h>
#include <stdlib.h>

// Function to compare integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to check if cows can be placed with minimum distance
int canPlaceCows(int stalls[], int n, int cows, int distance) {
    int count = 1;
    int lastPosition = stalls[0];

    for(int i = 1; i < n; i++) {
        if(stalls[i] - lastPosition >= distance) {
            count++;
            lastPosition = stalls[i];

            if(count >= cows) {
                return 1;
            }
        }
    }

    return 0;
}

// Function to find the largest minimum distance
int aggressiveCows(int stalls[], int n, int cows) {
    // Sort stall positions
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(canPlaceCows(stalls, n, cows, mid)) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n, k;

    // Input number of stalls and cows
    printf("Enter number of stalls and cows: ");
    scanf("%d %d", &n, &k);

    int stalls[n];

    // Input stall positions
    printf("Enter stall positions:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Find maximum minimum distance
    int result = aggressiveCows(stalls, n, k);

    // Print result
    printf("Maximum possible minimum distance: %d\n", result);

    return 0;
}