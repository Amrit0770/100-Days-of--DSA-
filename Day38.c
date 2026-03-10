/*
Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. 
It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations
*/


#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int empty() {
    if(front == -1)
        return 1;
    return 0;
}

int size() {
    if(empty())
        return 0;
    return rear - front + 1;
}

void push_front(int value) {

    if(front == -1 && rear == -1) {
        front = rear = 0;
    }
    else if(front == 0) {
        printf("Cannot insert at front (Overflow)\n");
        return;
    }
    else {
        front--;
    }

    deque[front] = value;
    printf("Inserted %d at front\n", value);
}

void push_back(int value) {

    if(rear == MAX-1) {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = value;
    printf("Inserted %d at rear\n", value);
}

void pop_front() {

    if(empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed %d from front\n", deque[front]);

    if(front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
}

void pop_back() {

    if(empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed %d from rear\n", deque[rear]);

    if(front == rear) {
        front = rear = -1;
    }
    else {
        rear--;
    }
}

void getFront() {

    if(empty())
        printf("Deque is empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

void getBack() {

    if(empty())
        printf("Deque is empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

void clear() {
    front = rear = -1;
    printf("Deque cleared\n");
}

void display() {

    if(empty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");

    for(int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }

    printf("\n");
}

void reverse() {

    if(empty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front, j = rear, temp;

    while(i < j) {
        temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }

    printf("Deque reversed\n");
}

void sort() {

    if(empty()) {
        printf("Deque is empty\n");
        return;
    }

    int i, j, temp;

    for(i = front; i <= rear; i++) {
        for(j = i + 1; j <= rear; j++) {
            if(deque[i] > deque[j]) {
                temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
        }
    }

    printf("Deque sorted in ascending order\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);

    display();

    getFront();
    getBack();

    pop_front();
    pop_back();

    display();

    push_back(15);
    push_back(8);

    display();

    sort();
    display();

    reverse();
    display();

    printf("Size of deque: %d\n", size());

    clear();
    display();

    return 0;
}