/*
Your task is to add two reversed numbers and output their reversed sum. Of course, the result is not unique because any particular number is a reversed form of several numbers (e.g. 21 could be 12, 120 or 1200 before reversing). Thus we must assume that no zeros were lost by reversing (e.g. assume that the original number was 12).


Sample input: 

3
24 1
4358 754
305 794

Sample output:

34
1998
1

*/

/* Insert each digit into Queue and compute till 0 . Now compute reversed integer */

# include <iostream>
# include <queue>

using namespace std;

long reverse(long data)
{
    long multiplier,result=0,temp=1;
    queue<long> q;
    while(data > 0)
    {
        q.push(data%10);
        data/=10;
        temp*=10;
    }
    temp/=10;
    while(!q.empty())
    {
        result += temp*q.front();
        q.pop();
        temp/=10;
    }
    return result;
}
int main()
{
    int size;
    long input1,input2;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>input1;
        cin>>input2;
        cout<<reverse(reverse(input1)+reverse(input2))<<endl;
    }
}

