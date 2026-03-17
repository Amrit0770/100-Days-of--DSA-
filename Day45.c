/*
Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3
*/


#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int height(struct Node* root)
{
    if(root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    if(left > right)
        return left + 1;
    else
        return right + 1;
}

int main()
{
    int n;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter level order traversal (-1 for NULL):\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct Node* nodes[n];

    for(int i=0;i<n;i++)
    {
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        if(nodes[i] != NULL)
        {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    struct Node* root = nodes[0];

    printf("Height of the tree:\n");
    printf("%d", height(root));

    return 0;
}