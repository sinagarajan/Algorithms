http://ideone.com/NKhUHy

/* Enter your code here. Read input from STDIN. Print output to STDOUT */

# include <iostream>
# include <string.h>
using namespace std;

int array[201][201];
int temp = 0;
void checkMasterBomb(int x,int y)
{
    array[x][y] = 0;
    if(x-1 >=0 && array[x-1][y]==1)
    {
        if(!temp) ++temp;
        checkMasterBomb(x-1,y);
    }
    if(x+1 <201 && array[x+1][y]==1)
    {
        if(!temp) ++temp;
        checkMasterBomb(x+1,y);
    }
    if(y-1>=0 && array[x][y-1]==1)
    {
        if(!temp) ++temp;
        checkMasterBomb(x,y-1);
    }
    if(y+1<201 && array[x][y+1] == 1)
    {
        if(!temp) ++temp;
        checkMasterBomb(x,y+1);
    }
    
    // Comb direction
    
    if(x-1 >=0 && y-1>=0 && array[x-1][y-1] == 1)
    {
        if(!temp) ++temp;
        checkMasterBomb(x-1,y-1);
    }
    
    if(x-1 >=0 && y+1 < 201 && array[x-1][y+1] ==1)
    {
        if(!temp) ++temp;
        checkMasterBomb(x-1,y+1);
    }
    
    if(x+1<201 && y-1>=0 && array[x+1][y-1] == 1)
    {
        if(!temp) ++temp;
        checkMasterBomb(x+1,y-1);
    }
    
    if(x+1<201 && y+1<201 && array[x+1][y+1] == 1)
    {
        if(!temp) ++temp;
        checkMasterBomb(x+1,y-1);
    }       
    
    return;
}

int main()
{
    int size,bombs,x,y,sum;
    cin>>size;
    while(size--)
    {
        sum=0;
        memset(array,0,sizeof(array));
        cin>>bombs;
        sum = 0;
        for(int i=0; i<bombs; ++i)
        {
            cin>>x;
            cin>>y;
            array[x][y]=1;
        }
        for(int i =0; i<201; ++i)
        {
            for(int j=0; j<201; ++j)
            {
                temp=0;
                if(array[i][j] == 1)
                {
                    checkMasterBomb(i,j);
                }
                sum += temp;
            }
        }
        cout<<sum<<endl;
    }
}
       

