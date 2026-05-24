/*
Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.

Lower Bound: The index of the first element in the array that is greater than or equal to x.
Upper Bound: The index of the first element in the array that is strictly greater than x.

Input:
- First line: integer n representing the size of the array
- Second line: n space-separated sorted integers
- Third line: integer x (the target value)

Output:
- Print two integers:
  1) Index of the lower bound of x
  2) Index of the upper bound of x

Example:
Input:
7
1 2 4 4 4 5 7
4

Output:
2 5

Explanation:
For the given array [1, 2, 4, 4, 4, 5, 7] and x = 4:
- The lower bound is at index 2, which is the first occurrence of 4.
- The upper bound is at index 5, which is the first element greater than 4 (i.e., 5).
Binary Search is used to find both bounds efficiently in O(log n) time.
*/

#include <stdio.h>

// Function to find Lower Bound
int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

// Function to find Upper Bound
int upperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, x, i;

    // Input size of array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input sorted array
    printf("Enter %d sorted integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input target value
    printf("Enter the target value: ");
    scanf("%d", &x);

    // Find bounds
    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    // Print results
    printf("Lower Bound Index: %d\n", lb);
    printf("Upper Bound Index: %d\n", ub);

    return 0;
}