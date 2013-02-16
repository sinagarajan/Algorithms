# include "ll.h"

int main()
{
int i,input,input1,*array;
struct node *head=createNode(5);
struct tree *itr;
while(1)
{
        cout<<"\nEnter the option \n1  Insert into Linked List"<<
                                "\n2  Display"<<
                                "\n3  Reverse Inplace"<<
                                "\n4  Reverse N nodes"<<
                                "\n5  Reverse n traverse"<<
                                "\n6  Sorted Linked List to BST"<<
                                "\n50 Exit\n";
        scanf("%d",&i);
        switch (i)
        {
        case 1:
                printf("\nEnter the value\n");scanf("%d",&input);
                insertNode(&head,input);
                break;
        case 2:
                display(head);
                break;
        case 3:
                head=reverseInplace(head);
                display(head);
                head=reverseRecursion(head);
                display(head);
                break;
        case 4:
                printf("\nEnter the value\n");scanf("%d",&input);
                head=reverseNNodes(head,input);
                display(head);
                break;
        case 5:
                printf("\nEnter the value for traverse\n");scanf("%d",&input);
                printf("\nEnter the value for reverse\n");scanf("%d",&input1);
                head=reverseNtraverse(head,input,input1,1);
                display(head);
                break;
        case 6:
                itr=convertSortedLLtoBST(head,0,4);
                printLevelorder(itr);
                break;
        case 50:
                exit(1);
        default:
                printf("Enter correct option\n");
                break;
        }
}

}

