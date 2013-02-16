#include<iostream>
#include<stdio.h>
#include<queue>
#include<stack>
#include<deque>

using namespace std;

struct tree
{
        struct tree *left;
        struct tree *right;
        int data;
};



struct tree * createNode(int data);


struct tree * insertNodeBST(struct tree* root,int data);


struct tree * insertNodeBT(struct tree* root,int data);


void printInorderRecursive(struct tree *root);


void printPreorderRecursive(struct tree *root);

void printPostorderRecursive(struct tree *root);


void printLevelorder(struct tree *root);

int countNode(struct tree *root);

int findMaxBT(struct tree *root);


int findMinBT(struct tree *root);


int findIsBST(struct tree *root);


int findIsBST1(struct tree *root,int min,int max);


void printReverse(struct tree *root);

void printZigZag(struct tree *root);

void printZigZagStack(struct tree *root);

struct tree *findLCA(struct tree * root, int a, int b);

int  printMaxHeight(struct tree *root);

void printArray(int paths[],int pathLen);

void printAll(struct tree *root,int path[],int pathLen);

void printAllPaths(struct tree *root);

int printAncestors(struct tree *root,int a);

int findDiameter(struct tree *root);

struct tree * convertSortedArraytoBST(int array[],int start,int end);
