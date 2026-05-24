/*
Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.
*/

#include <stdio.h>

#define MAX 100

// Function to perform insertion sort on each bucket
void insertionSort(float bucket[], int count) {
    int i, j;
    float key;

    for(i = 1; i < count; i++) {
        key = bucket[i];
        j = i - 1;

        while(j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

// Function to perform Bucket Sort
void bucketSort(float arr[], int n) {
    // Create buckets
    float buckets[MAX][MAX];
    int bucketCount[MAX] = {0};

    // Distribute elements into buckets
    for(int i = 0; i < n; i++) {
        int index = arr[i] * n;
        buckets[index][bucketCount[index]] = arr[i];
        bucketCount[index]++;
    }

    // Sort individual buckets
    for(int i = 0; i < n; i++) {
        insertionSort(buckets[i], bucketCount[i]);
    }

    // Concatenate all buckets into original array
    int k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < bucketCount[i]; j++) {
            arr[k] = buckets[i][j];
            k++;
        }
    }
}

int main() {
    int n;

    // Input size of array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n];

    // Input array elements
    printf("Enter %d real numbers in range [0,1):\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Perform Bucket Sort
    bucketSort(arr, n);

    // Print sorted array
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++) {
        printf("%.3f ", arr[i]);
    }

    return 0;
}

