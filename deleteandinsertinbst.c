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

struct bstnode *findMinnode(struct bstnode *root)
{
    struct bstnode *temp = root;
    if (root == NULL)
    {
        printf("\nTree is empty");
        return root;
    }
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

struct bstnode *delete (struct bstnode *root, int data)
{

    if (root == NULL)
    {
        printf("\nTree is empty");

        return root;
    }
    else if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else // when "data == root->data" i.e. we have found the key node to  be deleted
    {
        if (root->left == NULL && root->right == NULL) // case 1 : when both the childs of the deleting nodes are null
        {
            free(root);
            root = NULL;
            return root;
        }
        else if (root->left == NULL) // case 2 : one child of the deleting node is null
        {
            struct bstnode *temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if (root->right == NULL) // case 2 : one child of the deleting node is null
        {
            struct bstnode *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        else // case 3 : when both the childs of the node are not null
        {    // so for it find the minimum element from the right branch of the root
            struct bstnode *temp = root;
            temp = findMinnode(root->right);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
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

    printf("\n\n");
    root = delete (root, 20);
    root = delete (root, 23);
    root = delete (root, 33);
    // root = delete (root, 333);
    inorder(root);

    getch();
    return 0;
}