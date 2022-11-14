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

    getch();
    return 0;
}