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

int search(struct bstnode *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->data == key)
    {
        printf("Data found");
        return 1;
    }
    else if (key <= root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
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
    printf("Content in tree is : ");
    inorder(root);
    search(root, 45);
    printf("  ");

    getch();
    return 0;
}