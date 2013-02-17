#include "binarytree.h"

int main()
{
int i,input,input1,*array;
struct tree *itr,*root=createNode(10);
//printf("%d",root->data);

while(1)
{
        cout<<"\nEnter the option \n1  Insert into Binary Search tree"<<
                                "\n2  Print Inorder Recursively"<<
                                "\n3  Print Postorder Recursively"<<
                                "\n4  Print Preorder Recursively"<<
                                "\n5  Print Level Order"<<
                                "\n6  Insert into Binary tree"<<
                                "\n7  Count the nodes"<<
                                "\n8  Find Maximum and Minimum"<<
                                "\n9  Is BST"<<
                                "\n10 Print in Reverse Order"<<
                                "\n11 Print in ZigZag manner using One Queue"<<
                                "\n12 Print in ZigZag manner using 2 Stacks"<<
                                "\n13 Maximum height of the tree"<<
                                "\n14 LCA"<<
                                "\n15 Print All paths"<<
                                "\n16 Print ancestors"<<
                                "\n17 Find Diamter of the tree"<<
                                "\n18 Convert sorted array to BST"<<
                                "\n19 Find Max BST"<<
				"\n20 Find Nodes in Circumference"<<
                                "\n50 Exit\n";
        scanf("%d",&i);
        switch (i)
        {
                case 1:
                        printf("\nEnter the value \n");scanf("%d",&input);
                        insertNodeBST(root,input);
                        break;
                case 2:
                        printInorderRecursive(root);
                        break;
                case 3:
                        printPostorderRecursive(root);
                        break;
                case 4:
                        printPreorderRecursive(root);
                        break;
                case 5:
                        printLevelorder(root);
                        break;
                case 6:
			printf("\nEnter the value \n");scanf("%d",&input);
			insertNodeBT(root,input);	
                        break;
                case 7:
                        input=countNode(root);
                        printf("\nNumber of nodes %d",input);
                        break;
                case 8:
                        printf("Maximum value is %d",findMaxBT(root));
                        printf("\nMinimum value is %d",findMinBT(root));
                        break;
                case 9:
                        if(findIsBST(root))
                                printf("\nIt's BST");
                        else
                                printf("\nIt's not a BST");
                        if(findIsBST1(root,0,32767))
                                printf("\nIt's BST");
                        else
                                printf("\nIt's not a BST");
                        break;
                case 10:
                        printReverse(root);
                        break;
                case 11:
                        printZigZag(root);
                        break;
                case 12:
                        printZigZagStack(root);
                        break;
                case 13:
                        input=printMaxHeight(root);
                        printf("\nHeight of the tree is %d",input);
                        break;
                case 14:
                        printf("\nEnter the value \n");scanf("%d",&input);
                        printf("\nEnter the value \n");scanf("%d",&input1);
                        itr=findLCA(root,input,input1);
                        if(itr)
                                {printf("\nLCA is %d",itr->data);}
                        break;
                case 15:
                        printAllPaths(root);
                        break;
                case 16:
                        printf("\nEnter the value \n");scanf("%d",&input);
                        printAncestors(root,input);
                        break;
                case 17:
                        printf("\nDiameter of the tree is %d",findDiameter(root));
                        break;
                case 18:
                        printf("\nEnter the size of the array\n");scanf("%d",&input);array=new int[input];
                        for(i=0;i<input;i++)
                                scanf("%d",&array[i]);
                        itr=convertSortedArraytoBST(array,0,input-1);
                        printLevelorder(itr);
                        break;
                case 19:
//                        itr=findLargestBSTSubtree(root);
//                        printLevelorder(itr);
			cout<<"not implemented yet\n";
                        break;
		case 20:
			findCircumference(root);
			break;
                case 50:
                        exit(1);
                default:
                        printf("Provide correct option\n");
        }
}
}

