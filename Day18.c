/*
Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3
*/

#include <stdio.h>

int main()
{
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter number of rotations (k): ");
    scanf("%d", &k);

    k = k % n;   

    printf("Rotated array:\n");

    for(int i = n - k; i < n; i++)
        printf("%d ", arr[i]);

    for(int i = 0; i < n - k; i++)
        printf("%d ", arr[i]);

    return 0;
}