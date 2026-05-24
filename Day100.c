/*
Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to store value and original index
struct Element {
    int value;
    int index;
};

// Merge function to count smaller elements on right
void merge(struct Element arr[], int left, int mid, int right, int count[]) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct Element L[n1], R[n2];

    // Copy data to temporary arrays
    for(int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for(int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    int rightCount = 0;

    // Merge while counting smaller elements
    while(i < n1 && j < n2) {
        if(L[i].value <= R[j].value) {
            count[L[i].index] += rightCount;
            arr[k++] = L[i++];
        }
        else {
            rightCount++;
            arr[k++] = R[j++];
        }
    }

    // Remaining elements in left array
    while(i < n1) {
        count[L[i].index] += rightCount;
        arr[k++] = L[i++];
    }

    // Remaining elements in right array
    while(j < n2) {
        arr[k++] = R[j++];
    }
}

// Merge Sort function
void mergeSort(struct Element arr[], int left, int right, int count[]) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        // Sort left half
        mergeSort(arr, left, mid, count);

        // Sort right half
        mergeSort(arr, mid + 1, right, count);

        // Merge sorted halves
        merge(arr, left, mid, right, count);
    }
}

int main() {
    int n;

    // Input size of array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int nums[n];
    struct Element arr[n];
    int count[n];

    // Initialize count array
    for(int i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Input array elements
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    // Perform merge sort and count smaller elements
    mergeSort(arr, 0, n - 1, count);

    // Print result
    printf("Count of smaller elements on right side:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}

