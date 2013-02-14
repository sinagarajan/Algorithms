/*

Find number of inversions in the array . Example : {1,3,4,2} . Right element  < Left Element . In this case 2 is less than 3 and 4 and hence inversions count=2

Using the merge sort find the inversions . [ Whenever right hand side is less, all the remaning elements in left contribute to the inversion count

*/

# include <iostream>

using namespace std;

/* Merge function uses temp array that sorts all chracters from left to right */

int merge(int *array,int left, int mid,int right)
{

        int inv=0;
        int temp[right-left+1];
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

int mergesort(int arr[],int left,int right)
{
        int inv=0;
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
        int arr[]={5,4,3,2,1};
        printf("Count is %d",mergesort(arr,0,4));
        for(int i=0;i<5;i++)
                printf("\t%d",arr[i]);
}
