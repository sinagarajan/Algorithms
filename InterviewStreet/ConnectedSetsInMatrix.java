/*
Given a 2–d matrix , which has only 1’s and 0’s in it. Find the total number of connected sets in that matrix.
 
 
Explanation:
Connected set can be defined as group of cell(s) which has 1 mentioned on it and have at least one other cell in that set with which they share the neighbor relationship. A cell with 1 in it and no surrounding neighbor having 1 in it can be considered as a set with one cell in it. Neighbors can be defined as all the cells adjacent to the given cell in 8 possible directions ( i.e N , W , E , S , NE , NW , SE , SW direction ). A cell is not a neighbor of itself.
 
 
Input format :
 
First line of the input contains T , number of test-cases.
Then follow T testcases. Each testcase has given format.
N [ representing the dimension of the matrix N X N ].
Followed by N lines , with N numbers on each line.
 
 
 
Ouput format :
 
For each test case print one line ,  number of connected component it has.
 
Sample Input :
 
4
4
0 0 1 0
1 0 1 0
0 1 0 0
1 1 1 1
4
1 0 0 1
0 0 0 0
0 1 1 0
1 0 0 1
5
1 0 0 1 1
0 0 1 0 0
0 0 0 0 0
1 1 1 1 1
0 0 0 0 0
8
0 0 1 0 0 1 0 0
1 0 0 0 0 0 0 1
0 0 1 0 0 1 0 1
0 1 0 0 0 1 0 0
1 0 0 0 0 0 0 0
0 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0
0 0 0 0 0 0 0 0
 
Sample output :
 
1
3
3
9
 
Constraint :
 
0 < T < 6 
0 < N < 1009 


Algorithm:

1. For each element in the array which is '1'

2. Traverse in all possible eight directions if it has '1' and make all the connected sets '0'

3. Return of 1 recursive function means it has 1 connected set

4. Iterate through entire array

*/


# include <iostream>

using namespace std;

/* Iterate recursively along 8 directions if it has 1 in any direction */

int findanswer(int **array, int row, int column, int length)
{
    array[row][column]=0;
    
      if(row+1<length && array[row+1][column] == 1)
      {
            findanswer(array,row+1,column,length);
      }
      if(row-1>=0 && array[row-1][column] == 1)
      {
            findanswer(array,row-1,column,length);
      }
      if(column+1<length && array[row][column+1] == 1)
      {
            findanswer(array,row,column+1,length);
      }
      if(column-1>=0 && array[row][column-1] == 1)
      {
            findanswer(array,row,column-1,length);
      }
   
      if(row+1<length && column+1<length && array[row+1][column+1] == 1)
      {
            findanswer(array,row+1,column+1,length);
      }
   
      if(row+1<length && column-1>=0 && array[row+1][column-1] == 1)
      {
            findanswer(array,row+1,column-1,length);
      }
   
      if(row-1>=0 && column+1<length && array[row-1][column+1] == 1)
      {
            findanswer(array,row-1,column+1,length);
      }
   
      if(row-1>=0 && column-1>=0 && array[row-1][column-1] == 1)
      {
            findanswer(array,row-1,column-1,length);
      }
    return 1;
}
                

int main()
{
    int test_cases,itr=0,length;
    cin>>test_cases;
    int answer[test_cases];
    for( int i=0; i < test_cases; i++)
    {
        cin>>length;
        
        /* Dynamic 2 D array initialization */
        
        int **array=new int*[length];
        answer[itr]=0;
        for( int j=0; j < length; j++)
        {
                array[j]=new int[length];
        }

        for( int j=0; j< length; j++)
        {
            for( int k=0; k < length; k++)
            {
                cin>>array[j][k];
            }
        }
        for( int j=0; j< length; j++)
        {
            for( int k=0; k < length; k++)
            {
                if(array[j][k] == 1)
                    answer[itr] += findanswer(array,j,k,length);
            }
        }
        
        cout<<answer[itr++] << endl;

        itr++;
        
        /* Array destructor */
        
        for(int j=0; j<length; j++)
        {
            delete[] array[j];
        }
        delete[] array;
    }
}