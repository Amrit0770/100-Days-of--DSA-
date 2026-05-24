/*
Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.
*/


#include <stdio.h>
#include <stdlib.h>

// Structure to store intervals
struct Interval {
    int start;
    int end;
};

// Compare function for sorting intervals by start time
int compare(const void *a, const void *b) {
    struct Interval *i1 = (struct Interval *)a;
    struct Interval *i2 = (struct Interval *)b;

    return i1->start - i2->start;
}

// Function to merge overlapping intervals
void mergeIntervals(struct Interval intervals[], int n) {
    // Sort intervals by start time
    qsort(intervals, n, sizeof(struct Interval), compare);

    // Temporary array to store merged intervals
    struct Interval merged[n];
    int index = 0;

    // Add first interval
    merged[index] = intervals[0];

    // Traverse remaining intervals
    for(int i = 1; i < n; i++) {
        // If intervals overlap
        if(intervals[i].start <= merged[index].end) {
            // Merge intervals
            if(intervals[i].end > merged[index].end) {
                merged[index].end = intervals[i].end;
            }
        }
        else {
            // Move to next interval
            index++;
            merged[index] = intervals[i];
        }
    }

    // Print merged intervals
    printf("Merged intervals:\n");
    for(int i = 0; i <= index; i++) {
        printf("[%d, %d]\n", merged[i].start, merged[i].end);
    }
}

int main() {
    int n;

    // Input number of intervals
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Interval intervals[n];

    // Input intervals
    printf("Enter start and end of each interval:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    // Merge overlapping intervals
    mergeIntervals(intervals, n);

    return 0;
}
