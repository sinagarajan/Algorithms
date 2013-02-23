/*

A fashion show rates participants according to their level of hotness. Two different fashion shows were organized, one for men and the other for women. A date for the third is yet to be decided ;) .

Now the results of both fashion shows are out. The participants of both the fashion shows have decided to date each other, but as usual they have difficuly in choosing their partners. The Maximum Match dating serive (MMDS) comes to their rescue and matches them in such a way that that maximizes the hotness bonds for all couples.

If a man has been rated at hotness level x and a women at hotness level y, the value of their hotness bond is x*y.

Both fashion shows contain N participants each. MMDS has done its job and your job is to find the sum of hotness bonds for all the couples that MMDS has proposed.
Input

The first line of the input contains an integer t, the number of test cases. t test cases follow.

Each test case consists of 3 lines:

    The first line contains a single integer N (1 <= N <= 1000).
    The second line contains N integers separated by single spaces denoting the hotness levels of the men.
    The third line contains N integers separated by single spaces denoting the hotness levels of the women.

All hotness ratings are on a scale of 0 to 10.
Output

For each test case output a single line containing a single integer denoting the sum of the hotness bonds for all pairs that MMDS has proposed.
Example

Input:
2
2
1 1
3 2
3
2 3 2
1 3 2

Output:
5
15

ALGORITHM:

1. Sort men and women hotness and multiply them 

*/

# include <iostream>
# include <algorithm>
# include <string.h>
using namespace std;

int main()
{
    int size,men[1000],women[1000],sum,N;
    cin>>size;
    while(size--)
    {
        memset(men,0,sizeof(men));
        memset(women,0,sizeof(women));
        sum=0;
        cin>>N;
        for(int i=0; i<N ;++i)
            cin>>men[i];
        for(int i=0; i<N ;++i)
            cin>>women[i];
        
        sort(men,men+N);
        sort(women,women+N);
        
        for(int i=0; i<N ;++i)
            sum+=(men[i]*women[i]);
            
        cout<<sum<<endl;
    }
}

