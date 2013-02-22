/* Find the problem in other program 

ALGORITHM

1. Static init will make all array elements 0
2. Start from 1,1 index
3. Add max(3 parent nodes) + current node 
4. Solution will be available in the last row

*/



# include <iostream>

using namespace std;

//Maximum of the 3 parent nodes

int maxi(int a, int b, int c)
{
	if((a>b)&&(a>c))
		return a;
	else if (b>c)
		return b;
	else
		return c;
}

int main()
{
    int array[200][200],size,rows,columns,max=0,i,j,k;

    cin>>size;

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

            array[j][k]=0;

	    //Add the current node with maximum of the earlier node

            for( k=1; k<=columns; k++)
            {
                array[j][k] += maxi(array[j-1][k-1],array[j-1][k],array[j-1][k+1]);
            }  
            
        }
        max=array[rows][1];

	//Find the answer at the last row of the matrix

        for(int j=1; j<= columns; j++)
        {
                max=maxi(max,array[rows][j],0);
        }
            cout<<max<<endl;
        
    }
}
