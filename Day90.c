/*
Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.
*/
#include <stdio.h>

// Function to check if boards can be painted within given time
int isPossible(int boards[], int n, int painters, int maxTime) {
    int painterCount = 1;
    int currentTime = 0;

    for(int i = 0; i < n; i++) {
        // If a single board exceeds maxTime
        if(boards[i] > maxTime) {
            return 0;
        }

        // Assign board to current painter if possible
        if(currentTime + boards[i] <= maxTime) {
            currentTime += boards[i];
        }
        else {
            // Assign to next painter
            painterCount++;
            currentTime = boards[i];

            // If painters exceed limit
            if(painterCount > painters) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to find minimum time required
int painterPartition(int boards[], int n, int painters) {
    int low = 0;
    int high = 0;
    int ans = -1;

    // Calculate total board length
    for(int i = 0; i < n; i++) {
        high += boards[i];
    }

    // Binary Search on answer
    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(isPossible(boards, n, painters, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, k;

    // Input number of boards and painters
    printf("Enter number of boards and painters: ");
    scanf("%d %d", &n, &k);

    int boards[n];

    // Input board lengths
    printf("Enter board lengths:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    // Find minimum painting time
    int result = painterPartition(boards, n, k);

    // Print result
    printf("Minimum time required: %d\n", result);

    return 0;
}