/*
Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* queue[100];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == 99) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (!isEmpty()) {
        int levelSize = size();

        for (int i = 0; i < levelSize; i++) {
            struct Node* temp = dequeue();
            printf("%d ", temp->data);

            if (temp->left != NULL)
                enqueue(temp->left);

            if (temp->right != NULL)
                enqueue(temp->right);
        }
        printf("\n");
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    levelOrder(root);

    return 0;
}