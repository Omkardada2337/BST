#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* getnewnode(int data)
{
    struct node* newnode=(struct newnode*)malloc(sizeof(struct node));
    newnode->data=data;
    
}

int main()
{
    int i;
    system("cls");

    printf("  ");

    getch();
    return 0;
}