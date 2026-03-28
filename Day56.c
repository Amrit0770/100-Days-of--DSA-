/*
Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int isMirror(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL) {
        printf("Both NULL\n");
        return 1;
    }

    if (t1 == NULL || t2 == NULL) {
        printf("Mismatch NULL\n");
        return 0;
    }

    printf("Compare %d %d\n", t1->data, t2->data);

    if (t1->data != t2->data) {
        printf("Not Equal\n");
        return 0;
    }

    return isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

int isSymmetric(struct Node* root) {
    if (root == NULL) return 1;
    return isMirror(root->left, root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* nodes[n];

    for (int i = 0; i < n; i++)
        nodes[i] = newNode(arr[i]);

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int l = 2*i + 1;
            int r = 2*i + 2;

            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }

    printf("--- Checking Symmetry ---\n");

    if (isSymmetric(nodes[0]))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}