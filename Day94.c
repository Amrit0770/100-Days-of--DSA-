/*
Problem: Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output.
*/

#include <stdio.h>

// Function to perform Counting Sort
void countingSort(int arr[], int n) {
    int i;

    // Find maximum element
    int max = arr[0];
    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    // Create frequency array
    int count[max + 1];

    // Initialize count array to 0
    for(i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Store frequency of each element
    for(i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Compute prefix sums
    for(i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Build output array
    int output[n];

    // Traverse from end to maintain stability
    for(i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy sorted elements back to original array
    for(i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n, i;

    // Input size of array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d non-negative integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform Counting Sort
    countingSort(arr, n);

    // Print sorted array
    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

