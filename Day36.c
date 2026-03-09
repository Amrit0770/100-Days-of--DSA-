/*
Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. 
Display remaining elements in correct order.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);

    int *queue = (int *)malloc(n * sizeof(int));

    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        rear = (rear + 1) % n;
        queue[rear] = x;
        printf("Enqueued: %d\n", x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        if (front == (rear + 1) % n) {
            printf("Queue Underflow\n");
            break;
        }
        printf("Dequeued: %d\n", queue[front]);
        front = (front + 1) % n;
    }

    printf("Queue elements: ");

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % n;
    }

    free(queue);
    return 0;
}