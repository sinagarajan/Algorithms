#include<stdio.h>
#include <iostream>
#include <queue>

using namespace std;

struct node
{
        int data;
        struct node *next;
};

struct tree
{
        struct tree *left;
        struct tree *right;
        int data;
};

struct node * createNode(int data);

struct tree * createNodes(int data);

void printLevelorder(struct tree *root);

struct node *  reverseNNodes(struct node *head,int n);

struct  node * reverseNtraverse(struct node *head,int m,int n,int flag);

struct tree* convertSortedLLtoBST(struct node *& head, int start, int end);

struct node * reverseRecursion(struct node *head);

struct node * reverseInplace(struct node *head);

void insertNode(struct node **head,int data);

void display(struct node *head);
