/*
Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that 
each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).
*/
#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int books[], int n, int students, int maxPages) {
    int studentCount = 1;
    int currentPages = 0;

    for(int i = 0; i < n; i++) {
        // If a single book has more pages than maxPages
        if(books[i] > maxPages) {
            return 0;
        }

        // Allocate book to current student if possible
        if(currentPages + books[i] <= maxPages) {
            currentPages += books[i];
        }
        else {
            // Allocate to next student
            studentCount++;
            currentPages = books[i];

            // If students exceed limit
            if(studentCount > students) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to find minimum possible maximum pages
int allocateBooks(int books[], int n, int students) {
    int low = 0;
    int high = 0;
    int ans = -1;

    // Calculate total pages
    for(int i = 0; i < n; i++) {
        high += books[i];
    }

    // Binary Search on answer
    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(isPossible(books, n, students, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, m;

    // Input number of books and students
    printf("Enter number of books and students: ");
    scanf("%d %d", &n, &m);

    int books[n];

    // Input pages in books
    printf("Enter pages in books:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }

    // Find minimum possible maximum pages
    int result = allocateBooks(books, n, m);

    // Print result
    printf("Minimum possible maximum pages: %d\n", result);

    return 0;
}