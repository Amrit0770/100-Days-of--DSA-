/*
Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous 
subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.
*/

#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        printf("\nStarting from index %d\n", i);

        for (int j = i; j < n; j++) {
            sum += arr[j];
            printf("Adding arr[%d]=%d, Current sum=%d\n", j, arr[j], sum);

            if (sum == 0) {
                int length = j - i + 1;
                printf("Zero sum subarray found from %d to %d, length=%d\n", i, j, length);

                if (length > maxLen) {
                    maxLen = length;
                    printf("Updated max length = %d\n", maxLen);
                }
            }
        }
    }

    printf("\nFinal Answer (Max Length) = %d\n", maxLen);

    return 0;
}