/*
Problem: Count number of inversions using modified merge sort.
Inversion if i < j and a[i] > a[j].
*/

#include <stdio.h>

// Function to merge two subarrays and count inversions
long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long inversions = 0;

    // Merge while counting inversions
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1);
        }
    }

    // Copy remaining elements from left subarray
    while(i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from right subarray
    while(j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy merged elements back to original array
    for(i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inversions;
}

// Function to perform Merge Sort and count inversions
long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inversions = 0;

    if(left < right) {
        int mid = left + (right - left) / 2;

        // Count inversions in left half
        inversions += mergeSort(arr, temp, left, mid);

        // Count inversions in right half
        inversions += mergeSort(arr, temp, mid + 1, right);

        // Count split inversions during merge
        inversions += merge(arr, temp, left, mid, right);
    }

    return inversions;
}

int main() {
    int n;

    // Input size of array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];

    // Input array elements
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Count inversions
    long long inversionCount = mergeSort(arr, temp, 0, n - 1);

    // Print inversion count
    printf("Number of inversions: %lld\n", inversionCount);

    return 0;
}

