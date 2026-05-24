/*
Problem: Implement Binary Search Iterative - Implement the algorithm.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the sorted array or search result

Example:
Input:
5
64 34 25 12 22

Output:
12 22 25 34 64
*/
#include <stdio.h>

// Function to perform Iterative Binary Search
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target) {
            return mid;
        }
        else if(arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n, i, target;

    // Input size of array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input sorted array elements
    printf("Enter %d sorted integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input target element
    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Perform Binary Search
    int result = binarySearch(arr, n, target);

    // Print result
    if(result != -1) {
        printf("Element found at index: %d\n", result);
    }
    else {
        printf("Element not found\n");
    }

    return 0;
}