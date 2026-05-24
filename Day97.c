/*
Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.
*/



#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to store meeting intervals
struct Meeting {
    int start;
    int end;
};

// Min-Heap structure
struct MinHeap {
    int heap[MAX];
    int size;
};

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(struct MinHeap *h, int index) {
    while(index > 0) {
        int parent = (index - 1) / 2;

        if(h->heap[parent] > h->heap[index]) {
            swap(&h->heap[parent], &h->heap[index]);
            index = parent;
        }
        else {
            break;
        }
    }
}

// Heapify down
void heapifyDown(struct MinHeap *h, int index) {
    while(1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if(left < h->size && h->heap[left] < h->heap[smallest]) {
            smallest = left;
        }

        if(right < h->size && h->heap[right] < h->heap[smallest]) {
            smallest = right;
        }

        if(smallest != index) {
            swap(&h->heap[index], &h->heap[smallest]);
            index = smallest;
        }
        else {
            break;
        }
    }
}

// Insert into min-heap
void insertHeap(struct MinHeap *h, int value) {
    h->heap[h->size] = value;
    heapifyUp(h, h->size);
    h->size++;
}

// Remove minimum element from heap
void removeMin(struct MinHeap *h) {
    if(h->size == 0) {
        return;
    }

    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
}

// Get minimum element from heap
int getMin(struct MinHeap *h) {
    return h->heap[0];
}

// Compare function for sorting meetings by start time
int compare(const void *a, const void *b) {
    struct Meeting *m1 = (struct Meeting *)a;
    struct Meeting *m2 = (struct Meeting *)b;

    return m1->start - m2->start;
}

// Function to find minimum meeting rooms required
int minMeetingRooms(struct Meeting meetings[], int n) {
    // Sort meetings by start time
    qsort(meetings, n, sizeof(struct Meeting), compare);

    struct MinHeap heap;
    heap.size = 0;

    // Add end time of first meeting
    insertHeap(&heap, meetings[0].end);

    int maxRooms = 1;

    for(int i = 1; i < n; i++) {
        // If current meeting starts after earliest ending meeting
        if(meetings[i].start >= getMin(&heap)) {
            removeMin(&heap);
        }

        // Add current meeting end time
        insertHeap(&heap, meetings[i].end);

        // Update maximum rooms needed
        if(heap.size > maxRooms) {
            maxRooms = heap.size;
        }
    }

    return maxRooms;
}

int main() {
    int n;

    // Input number of meetings
    printf("Enter number of meetings: ");
    scanf("%d", &n);

    struct Meeting meetings[n];

    // Input meeting intervals
    printf("Enter start and end times of meetings:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    // Find minimum meeting rooms required
    int result = minMeetingRooms(meetings, n);

    // Print result
    printf("Minimum meeting rooms required: %d\n", result);

    return 0;
}