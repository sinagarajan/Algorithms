/*
Farmer John tries to keep the cows sharp by letting them play with intellectual toys. One of the larger toys is the lights in the barn.  Each of the N (2 <= N <= 100,000) cow stalls conveniently numbered 1..N has a colorful light above it.

At the beginning of the evening, all the lights are off. The cows control the lights with a set of N pushbutton switches that toggle the lights; pushing switch i changes the state of light i from off to on or from on to off.

The cows read and execute a list of M (1 <= M <= 100,000) operations expressed as one of two integers (0 <= operation <= 1).

The first kind of operation (denoted by a 0 command) includes two subsequent integers S_i and E_i (1 <= S_i <= E_i <= N) that indicate a starting switch and ending switch. They execute the operation by pushing each pushbutton from S_i through E_i inclusive exactly once.

The second kind of operation (denoted by a 1 command) asks the cows to count how many lights are on in the range given by two integers S_i and E_i (1 <= S_i <= E_i <= N) which specify the inclusive range in which the cows should count the number of lights that are on.

Help FJ ensure the cows are getting the correct answer by processing the list and producing the proper counts.
Input


Line 1: Two space-separated integers: N and M
Lines 2..M+1: Each line represents an operation with three space-separated integers: operation, S_i, and E_i
Output

Lines 1..number of queries: For each output query, print the count as an integer by itself on a single line.
Example

Input:
4 5
0 1 2
0 2 4
1 2 3
0 2 4
1 1 4

Output:
1
2

ALGORITHM

1. Just have an array with size specified 
2. For each command mark it as 1 or 0 as per request

NOTE: This still time outs since the time limit is too small 

*/


# include <stdio.h>
# include <cstring>
  
int main(void)
{
    int size,test,start,end,count,onoff;
    scanf("%d",&size);
    int array[size+1];
    memset(array, 0, sizeof(array));
    scanf("%d",&test);
    while(test--) 
    {
        scanf("%d",&onoff);
        scanf("%d",&start);
        scanf("%d",&end);
        if(start > end)
        {
            start = start ^ end;
            end = start ^ end;
            start = start ^ end;
        }
        if(onoff)
        {
            count=0;
            for(int i=start; i<=end; ++i)
            {
                if(array[i]==1)
                    ++count;
            }

            printf("%d\n",count);
        }
        else
        {
            for(int i=start; i<=end; ++i)
            {
                array[i]^=1;
            }

        }            
    }
    return 0;
}
    
      

