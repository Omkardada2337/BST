#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    int x;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : (else enter -1 for null) : ");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    newnode->data = x;
    printf("\nEnter the data of left child of %d : ", x);
    newnode->left = create();
    printf("\nEnter the data of right child of %d : ", x);
    newnode->right = create();
    return newnode;
}
void preorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
void inorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main()
{
    struct node *root;
    system("cls");
    root = create();
    preorder(root);
    printf(" \n");
    postorder(root);
    printf(" \n");
    inorder(root);
    printf(" \n");
    getch();
    return 0;
}