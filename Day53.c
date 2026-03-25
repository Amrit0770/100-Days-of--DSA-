/*

Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together 
from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int data;
    struct Node *left, *right;
};

struct QNode {
    struct Node* node;
    int hd;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    struct QNode queue[MAX];
    int front = 0, rear = 0;

    int map[MAX][MAX];   
    int count[MAX] = {0};

    int min = 0, max = 0;

    queue[rear++] = (struct QNode){root, 0};

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* node = temp.node;
        int hd = temp.hd + MAX/2;

        map[hd][count[hd]++] = node->data;

        if (temp.hd < min) min = temp.hd;
        if (temp.hd > max) max = temp.hd;

        if (node->left)
            queue[rear++] = (struct QNode){node->left, temp.hd - 1};

        if (node->right)
            queue[rear++] = (struct QNode){node->right, temp.hd + 1};
    }

    for (int i = min; i <= max; i++) {
        int idx = i + MAX/2;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of nodes:\n");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level order traversal (-1 for NULL):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    printf("Vertical Order Traversal:\n");
    verticalOrder(root);

    return 0;
}