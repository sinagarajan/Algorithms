#include "binarytree.h"


/* Creation of new Node */

struct tree * createNode(int data)
{
	struct tree *newNode= (struct tree *)malloc(sizeof(struct tree));
	newNode->data=data;
	newNode->right=newNode->left=NULL;
	return newNode;
}

/* Insert an element in the Binary Search tree */

struct tree * insertNodeBST(struct tree* root,int data)
{
	if(root==NULL)
		return createNode(data);
	else
	{
		if(data<=root->data)
			root->left=insertNodeBST(root->left,data);
		else
			root->right=insertNodeBST(root->right,data);
	}
return root;
}

/* Insert an element in the Binary Tree */

struct tree * insertNodeBT(struct tree* root,int data)
{
	queue<struct tree *> q;
	struct tree *ptr=createNode(data);
	struct tree *itr;
	if(root==NULL)
	{
                root=ptr;
	}
	else
	{
		q.push(root);
		while(!q.empty())
		{
			itr=q.front();
			q.pop();
			if(itr->left==NULL)
			{
				itr->left=ptr;
				break;
			}
			else if(itr->right==NULL)
			{
				itr->right=ptr;
				break;
			}
			else
			{
				q.push(itr->left);
				q.push(itr->right);
			}
		}
		/* Queue does not have standard clear */
		while(!q.empty()){q.pop();}
	}
return root;
}

/* Inorder Traversal */

void printInorderRecursive(struct tree *root)
{
	if(root==NULL)
		return;
	else
	{
		printInorderRecursive(root->left);
		printf("\t%d",root->data);
		printInorderRecursive(root->right);
	}
}

/* Pre order and Post Order Traversal */

void printPreorderRecursive(struct tree *root)
{
	if(root==NULL)
                return;
        else
        {
                printf("\t%d",root->data);
		printPreorderRecursive(root->left);
                printPreorderRecursive(root->right);
        }

}

void printPostorderRecursive(struct tree *root)
{
        if(root==NULL)
                return;
        else
        {
                printPostorderRecursive(root->left);
                printPostorderRecursive(root->right);
		printf("\t%d",root->data);
        }

}

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

/* Count number of nodes in a Binary tree */

int countNode(struct tree *root)
{
	if(root==NULL)
		return 0;
	else
	{
		return countNode(root->left)+countNode(root->right)+1;
	}
}

/* Find maximum element in binary tree */

int findMaxBT(struct tree *root)
{
	int a,b;
	if(root==NULL)
                return 0;
        else
        {
		a=findMaxBT(root->left);
		b=findMaxBT(root->right);
		return std::max(root->data,std::max(a,b));
	}
}

/* Find minimum element in binary tree */

int findMinBT(struct tree *root)
{
        int a,b;
        if(root==NULL)
                return 32767;
        else
        {
                a=findMinBT(root->left);
                b=findMinBT(root->right);
                return std::min(root->data,std::min(a,b));
        }
}

/* Find if tree is BST or not using Post order */

int findIsBST(struct tree *root)
{
	int a,b,c;
	if(root==NULL)
		return 1;
	else
	{
		a=findIsBST(root->left);
		b=findIsBST(root->right);
		c= a&& b;
		if(c==0 || root->data < findMaxBT(root->left) || (root->data > findMinBT(root->right)))
			return 0;
		else
			return 1;
	}
}

/* Is BST by passing min and max to leaves */

int findIsBST1(struct tree *root,int min,int max)
{
	if(root==NULL)
		return 1;
	if((root->data < min) || (root->data > max))
		return 0;

	if(!findIsBST1(root->left,min,root->data) || !findIsBST1(root->right,root->data,max))
		return 0;
	return 1;
}

/* Print tree in reverse order */

void printReverse(struct tree *root)
{
	stack<struct tree*> s;
	queue<struct tree*> q;
	struct tree *itr;
	if(root==NULL)return;
	q.push(root);
	while(!q.empty())
	{
		itr=q.front();
		q.pop();
		s.push(itr);
		if(itr->left!=NULL ) q.push(itr->left);
		if(itr->right!=NULL) q.push(itr->right);
	}
	while(!s.empty())
	{
		itr=s.top();
		s.pop();
		printf("\t%d",itr->data);
	}
}

/* Print in zig zag way */

void printZigZag(struct tree *root)
{
	deque<struct tree*> dq;
	struct tree *itr;
	int current,next,flag;
	if(root==NULL)return;
	dq.push_front(root);
	current=1;flag=0;next=0;

	while(1)
	{
		while(current >0 )
		{
			if(flag)
			{
				itr=dq.back();
				dq.pop_back();
				printf("\t%d",itr->data);
				if(itr->left != NULL){ dq.push_front(itr->left);next++;}
				if(itr->right != NULL){ dq.push_front(itr->right);next++;}
			}
			else
			{
				itr=dq.front();
				dq.pop_front();
				printf("\t%d",itr->data);
                                if(itr->right != NULL){ dq.push_back(itr->right);next++;}
                                if(itr->left != NULL){ dq.push_back(itr->left);next++;}
                        }
			current--;
		}
		++flag;
		flag%=2;
		// Break when it is last level
		if(next==0) break;
		current=next;
		next=0;
	}
}

/* Print the tree in zig zag way using two stacks */

void printZigZagStack(struct tree *root)
{
	stack<struct tree *> current,next,temp;
	struct tree *itr;
	int flag=1;
	if(root==NULL) return;
	current.push(root);
	while(!current.empty())
	{
		itr=current.top();
		current.pop();
		printf("\t%d",itr->data);
		if(flag)
		{
			if(itr->left != NULL) next.push(itr->left);
			if(itr->right!=NULL) next.push(itr->right);
		}
		else
		{
                        if(itr->right != NULL) next.push(itr->right);
                        if(itr->left!=NULL) next.push(itr->left);
		}
		if(current.empty())
		{
			current=next;
			next=temp;
			flag++;
			flag%=2;
		}
	}
}

/* Find Lowest Common Ancestor */

struct tree *findLCA(struct tree * root, int a, int b)
{
	if(root==NULL) return NULL;
	if(root->data==a || root->data==b)return root;
	struct tree *left=findLCA(root->left,a,b);
	struct tree *right=findLCA(root->right,a,b);
	if( left && right) return root;
	return left?left:right;
}

/* Maximum height */

int  printMaxHeight(struct tree *root)
{
	int left,right;
	if(root==NULL) return 0;
	left=printMaxHeight(root->left);
	right=printMaxHeight(root->right);
	return (std::max(left,right)+1);
}

/* Print All Paths */

void printArray(int paths[],int pathLen)
{
	for(int i=0;i<pathLen;i++)
		printf("\t%d",paths[i]);
	printf("\n");
}

void printAll(struct tree *root,int path[],int pathLen)
{
	if(root==NULL) return;
	path[pathLen]=root->data;
	pathLen++;
	if(root->left == NULL && root->right==NULL)
		printArray(path,pathLen);
	else
	{
		printAll(root->left,path,pathLen);
		printAll(root->right,path,pathLen);
	}

}

void printAllPaths(struct tree *root)
{
	int paths[1000];
	printAll(root,paths,0);
}

int printAncestors(struct tree *root,int a)
{
	if(root==NULL) return 0;
	if(root->data==a || printAncestors(root->left,a) || printAncestors(root->right,a))
		printf("\t%d",root->data);
		return 1;
}

/* Diamter of the tree */

int findDiameter(struct tree *root)
{
	int lheight,rheight,ldia,rdia;
	if(root==NULL) return 0;
	lheight = printMaxHeight(root->left);
	rheight = printMaxHeight(root->right);
	ldia=findDiameter(root->left);
	rdia=findDiameter(root->right);
	return std::max(lheight+rheight+1,std::max(ldia,rdia));
}

/* Sorted array using Binary Search Tree principle */

struct tree * convertSortedArraytoBST(int array[],int start,int end)
{
	int mid= (start + end)/2;
	struct tree *root;
	if(start > end) return NULL;
	root=createNode(array[mid]);
	root->left=convertSortedArraytoBST(array,start,mid-1);
	root->right=convertSortedArraytoBST(array,mid+1,end);
	return root;
}

int findLargestBSTSubtree(struct tree *p, int &min, int &max,
                   int &maxNodes, struct tree *& largestBST) {
  if (!p) return 0;
  bool isBST = true;
  int leftNodes = findLargestBSTSubtree(p->left, min, max, maxNodes, largestBST);
  int currMin = (leftNodes == 0) ? p->data : min;
  if (leftNodes == -1 ||
     (leftNodes != 0 && p->data <= max))
    isBST = false;
  int rightNodes = findLargestBSTSubtree(p->right, min, max, maxNodes, largestBST);
  int currMax = (rightNodes == 0) ? p->data : max;
  if (rightNodes == -1 ||
     (rightNodes != 0 && p->data >= min))
    isBST = false;
	printf("\nLeft Nodes %d",leftNodes);
	printf("\nRight Nodes %d",rightNodes);
	printf("\n%d is BST",isBST);
        printf("\nMAX: %d",max);
        printf("\nMIN: %d",min);
	printf("\np->data %d",p->data);
	printf("\nCMIN: %d",currMin);
	printf("\nCMAX: %d",currMax);
  if (isBST) {
    min = currMin;
    max = currMax;
    int totalNodes = leftNodes + rightNodes + 1;
    if (totalNodes > maxNodes) {
      maxNodes = totalNodes;
      largestBST = p;
    }
    return totalNodes;
  } else {
    return -1;   // This subtree is not a BST
  }
}

struct tree* findLargestBSTSubtree(struct tree *root) {
  struct tree *largestBST = NULL;
  int min, max;
  int maxNodes = INT_MIN;
  findLargestBSTSubtree(root, min, max, maxNodes, largestBST);
  return largestBST;
}

/* Find the nodes along the circumference of the tree . Select first and last nodes in each level followed by choosing the leaf nodes at each level */

void findCircumference(struct tree *root)
{
	int currLevel = 0, nextLevel =0 , count = 0;
	struct tree *itr;
	stack<struct tree *> s1;
	stack<struct tree *> s2;
	stack<struct tree *> temp;
	if(root == NULL)
		return ;
	s1.push(root);
	++currLevel;
	while(!s1.empty())
	{
		itr= s1.top();
		s1.pop();

		//Concept of same two stack used for zig zag traversal

		if(itr->left !=NULL)
		{
			s2.push(itr->left);
			++nextLevel;
		}
		if(itr->right != NULL)
		{
			s2.push(itr->right);
			++nextLevel;
		}

		//Check for node at the circumference

		if((itr->left == NULL && itr->right == NULL) || (count == 0) || (count == currLevel-1))
			printf("\t%d", itr->data);
		++count;
		if(s1.empty())
		{
			s1 = s2;
			s2 = temp;
			count=0;
			currLevel = nextLevel;
			nextLevel = 0;
		}

	}

}
