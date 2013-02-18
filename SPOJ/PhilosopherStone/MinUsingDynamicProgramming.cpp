/*
Jack is a wise and miser man. Always tries to save his money.

One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:

    At every city, he has to change the bus.

    And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.

You are to help Jack to go from A to B by spending the minimum amount of money.

N,M,K<=100.
Input

Line 1:    N M
Line 2:    NxM Grid

Each row lists the fares the M busses to go form the current city to the next city.
Output

Single Line containing the minimum amount of fare that Jack has to give.
Example

Input:
5 5
1 3 1 2 6
10 2 5 4 15
10 9 6 7 1
2 7 1 5 3
8 2 6 1 9

Output:
10

Explanation:
1->4->1->3->1 = 10
*/


# include <iostream>
# include <limits.h>

using namespace std;

//Maximum of the 3 parent nodes

int mini(int a, int b, int c)
{
    if((a<b)&&(a<c))
        return a;
    else if (b<c)
        return b;
    else
        return c;
}

int main()
{
    int array[110][110],size,rows,columns,min=0,i,j,k;

    size=1;

    for(int i=0; i<size; i++)
    {
        cin>>rows;
        cin>>columns;

        for(j=1; j<=rows; j++)
        {
            for( k=1; k<=columns; k++)
            {
                cin >> array[j][k];
            }

// We are not deleting the array. Since same array is used , make it 0 so that next iteration is not affected

            array[j][k]=INT_MAX;
            array[j][0]=INT_MAX;

//Add the current node with maximum of the earlier node

            for( k=1; k<=columns; k++)
            {
                array[j][k] += mini(array[j-1][k-1],array[j-1][k],array[j-1][k+1]);
            }
            
        }
        min=array[rows][1];

//Find the answer at the last row of the matrix

        for(int j=1; j<= columns; j++)
        {
                min=mini(min,array[rows][j],INT_MAX);
        }
            cout<<min<<endl;
        
    }
}

