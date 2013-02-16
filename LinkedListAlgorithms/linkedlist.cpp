# include "linkedlist.h"

using namespace std;

/* Create a Linked List node */

struct node * createNode(int data)
{
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}


/* Creation of Tree node */

struct tree * createNodes(int data)
{
        struct tree *newNode= (struct tree *)malloc(sizeof(struct tree));
        newNode->data=data;
        newNode->right=newNode->left=NULL;
        return newNode;
}

/* Breadth First Traversal for Tree */

void printLevelorder(struct tree *root)
{
        queue<struct tree*> q;
        struct tree *ptr;
        if(root==NULL)
                return;
        q.push(root);
        while(!q.empty())
        {
                ptr=q.front();
                q.pop();
                printf("\t%d",ptr->data);
                if(ptr->left != NULL)q.push(ptr->left);
                if(ptr->right != NULL)q.push(ptr->right);
        }
}

/* Insert node at head of Linked List */

void insertNode(struct node **head,int data)
{
	struct node *newNode=createNode(data);
	newNode->next=(*head);
	*head=newNode;
	return;
}

/* Display the Linked List */

void display(struct node *head)
{
	struct node *ptr=head;
	while(ptr!=NULL)
	{
		printf("\t%d",ptr->data);
		ptr=ptr->next;
	}
	return;
}

/* Reverse the linked list Inplace during traversal */

struct node *  reverseInplace(struct node *head)
{
	struct node *next,*prev=NULL,*current=head;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	return prev;
}

/* Reverse the linked list using Recursion */

struct node * reverseRecursion(struct node *head)
{
	struct node* itr;
	if(head==NULL || head->next==NULL) return head;

	itr=reverseRecursion(head->next);
	head->next->next=head;
	head->next=NULL;

	return itr;
}

/*  Reverse only 'n' nodes using Recursion Inplace */

struct node *  reverseNNodes(struct node *head,int n)
{
	struct node *current=head,*prev=NULL,*next;
	int count=1;
	while(current!=NULL && count<=n)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		count++;
	}
	if(next!=NULL)
		head->next=reverseNNodes(next,n);
	return prev;
}

/* Traverse and Reverse nodes m-traverse, n-reverse,flag -0 reverse first*/

struct  node * reverseNtraverse(struct node *head,int m,int n,int flag)
{
	struct node *current=head,*prev=NULL,*next,*stand,*itr;
        int count=1;
	if(flag==0)
	{
		while(current!=NULL && count<=n)
	        {
        	        next=current->next;
                	current->next=prev;
	                prev=current;
        	        current=next;
                	count++;
	        }
		count=1;
		head->next=current;
		while(current!=NULL && count<=m)
		{
			head=current;
			current=current->next;
			count++;
		}
		if(current!=NULL)
			head->next=reverseNtraverse(current,m,n,flag);
		return prev;
	}
	if(flag==1)
	{
		while(current!=NULL && count<=m)
                {
                        itr=current;
                        current=current->next;
                        count++;
                }
		stand=current;
		count=1;
		while(current!=NULL && count<=n)
                {
                        next=current->next;
                        current->next=prev;
                        prev=current;
                        current=next;
                        count++;
                }
		itr->next=prev;
		if(current!=NULL)
			stand->next=reverseNtraverse(current,m,n,flag);
		return head;
	}
}

/* 	Convert Sorted Linked List to BST using Binary Search Principle */

struct tree* convertSortedLLtoBST(struct node *& head, int start, int end)
{
	int mid= (start+end)/2;
	struct tree *root,*left;
	if(start > end) return NULL;
	left=convertSortedLLtoBST(head,start,mid-1);
	root=createNodes(head->data);
	root->left=left;
	head=head->next;
	root->right=convertSortedLLtoBST(head,mid+1,end);
	return root;
}

