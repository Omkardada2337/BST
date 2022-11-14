#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
};

struct bstnode *getnewnode(int data)
{
    struct bstnode *newnode = (struct bstnode *)malloc(sizeof(struct bstnode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct bstnode *insert(struct bstnode *root, int data)
{

    if (root == NULL)
    {
        root = getnewnode(data);
    }
    else if (data <= (root->data))
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

int findmin(struct bstnode *root)
{
    struct bstnode *temp = root;
    if (root == NULL)
    {
        printf("\nTree is empty");
        return -1;
    }
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}
// int findmin(struct bstnode *root)
// {
//     if (root==NULL)
//     {
//         printf("\nTree is empty");
//         return -1;
//     }
//     else if (root->left==NULL)
//     {
//         return root->data;
//     }
//     else
//     {
//         return findmin(root->left);
//     }
// }

int findmax(struct bstnode *root)
{
    struct bstnode *temp = root;
    if (root == NULL)
    {
        printf("\nTree is empty");
        return -1;
    }
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

// int findmax(struct bstnode *root) // local copy of address of root
// {
//     if (root == NULL)
//     {
//         printf("\nTree is empty");
//         return -1;
//     }
//     else if (root->right == NULL)
//     {
//         return root->data;
//     }
//     else
//     {
//         return findmax(root->right);
//     }
// }

void inorder(struct bstnode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main()
{
    int i;
    struct bstnode *root = NULL; // it is important
    system("cls");
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 23);
    root = insert(root, 10);
    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 35);
    root = insert(root, 33);
    root = insert(root, 45);
    inorder(root);
    printf("  ");
    printf("\n%d is the minimum number\n", findmin(root));
    printf("%d is the maximum number\n", findmax(root));

    getch();
    return 0;
}