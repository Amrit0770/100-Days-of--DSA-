/*
Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return create(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int search(struct Node* root, int key) {
    if (root == NULL) {
        printf("Reached NULL, element not found\n");
        return 0;
    }

    printf("Visiting node: %d\n", root->val);

    if (root->val == key) {
        printf("Element found\n");
        return 1;
    }

    if (key < root->val) {
        printf("Going left\n");
        return search(root->left, key);
    } else {
        printf("Going right\n");
        return search(root->right, key);
    }
}

int main() {
    int n, x, key;
    struct Node* root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    if (!search(root, key))
        printf("Element not found in BST\n");

    return 0;
}
