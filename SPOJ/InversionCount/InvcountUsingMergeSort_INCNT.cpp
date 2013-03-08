/*
Let A[0...n - 1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. Given n and an array A your task is to find the number of inversions of A.
Input

The first line contains t, the number of testcases followed by a blank space. Each of the t tests start with a number n (n <= 200000). Then n + 1 lines follow. In the ith line a number A[i - 1] is given (A[i - 1] <= 10^7). The (n + 1)th line is a blank space.
Output

For every test output one line giving the number of inversions of A.
Example

Input:

2

3
3
1
2

5
2
3
8
6
1


Output:

2
5


ALGORITHM :

1. Use Merge Sort 
2. One of the merge sort - Right Hand Side - will be invoked indicates inv count

*/





# include <stdio.h>
# include <iostream>
# include <string.h>
typedef unsigned long long ullong;
using namespace std;

/* Merge function uses temp array that sorts all chracters from left to right */

ullong merge(ullong *array,int left, int mid,int right)
{

        ullong inv=0;
        ullong temp[right-left+1];
        int pos=0,lpos=left,rpos=mid+1;
        while(lpos <=mid && rpos <= right)
        {
                if( array[lpos] < array[rpos])
                {
                        temp[pos]=array[lpos];
                        lpos++;
                }
                else
                {
                        temp[pos]=array[rpos];
                        rpos++;

                        /* In case {1,3,4} and {2} , it has two inversions */

                        inv+= (mid-lpos+1);
                }
                pos++;
        }

        /* Fill the remaining elemets */

        while(lpos<=mid)
        {
                temp[pos++]=array[lpos++];
        }
        while(rpos<=right)
        {
                temp[pos++]=array[rpos++];
        }
        int iter;

        /* Copy back the sorted array to the original array */

        for(iter = 0;iter < pos; iter++)
        {
                array[iter+left] = temp[iter];
        }
        return inv;
}

/* Merge functions that divides and call the conquers */

ullong mergesort(ullong arr[],int left,int right)
{
        ullong inv=0;
        int mid=(left+right)/2;
        if(right > left)
        {
                inv=mergesort(arr,left,mid);
                inv+=mergesort(arr,mid+1,right);
                inv+=merge(arr,left,mid,right);
        }
        return inv;
}

int main()
{
    ullong array[200001];
    int tests,inputs;
    scanf("%d",&tests);
    while(tests--)
    {
        scanf("%d",&inputs);
        memset(array,0,sizeof(array));
        for(int i=0; i< inputs;++i)
        {
            cin>>array[i];
        }
        cout<<mergesort(array,0,inputs-1)<<endl;
    }
}



