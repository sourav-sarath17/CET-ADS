#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode;
struct node *createNode(data)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct node *insertNode(struct node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}
void dispTree(struct node *root)
{
    if (root != NULL)
    {
        dispTree(root->left);
        printf("%d ", root->data);
        dispTree(root->right);
    }
}
struct node *minNode(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
        return root;
    }
}
struct node *delete(struct node *root, int val)
{
    if (val < root->data)
    {
        root->left = delete (root->left, val);
    }
    else if (val > root->data)
    {
        root->right = delete (root->right, val);
    }
    else
    {
        if (root->left == NULL && root->right == NULL) // if node has no children
        {
            root = NULL;
            printf("\nNode with no children deleted\n");
        }
        else if (root->left == NULL)
        {
            root = root->right;
            root->right = NULL;
            printf("\nNode with no left children deleted\n");
        }
        else if (root->right == NULL)
        {
            root = root->left;
            root->left = NULL;
            printf("\nNode with no right children deleted\n");
        }
        else
        {
            root->data = minNode(root->right)->data;
            root->right = delete (root->right, root->data);
            printf("\nNode with 2 children deleted\n");
        }
    }
    return root;
}
void main()
{
    int i, n, ch = 1;
    struct node *root = NULL;
    while (ch != 0)
    {
        printf("\nEnter 1 to Insert, 2 to display,3 to delete, 0 to exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &n);
            root = insertNode(root, n);
            break;
        case 2:
            dispTree(root);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &n);
            root = delete (root, n);
        }
    }
}
