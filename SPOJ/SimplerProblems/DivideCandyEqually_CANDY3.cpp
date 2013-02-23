/*

A class went to a school trip. And, as usually, all N kids have got their backpacks stuffed with candy. But soon quarrels started all over the place, as some of the kids had more candies than others. Soon, the teacher realized that he has to step in: "Everybody, listen! Put all the candies you have on this table here!"

Soon, there was quite a large heap of candies on the teacher's table. "Now, I will divide the candies into N equal heaps and everyone will get one of them." announced the teacher.

"Wait, is this really possible?" wondered some of the smarter kids.
Problem specification

You are given the number of candies each child brought. Find out whether the teacher can divide the candies into N exactly equal heaps. (For the purpose of this task, all candies are of the same type.)
Input specification

The first line of the input file contains an integer T specifying the number of test cases. Each test case is preceded by a blank line.

Each test case looks as follows: The first line contains N : the number of children. Each of the next N lines contains the number of candies one child brought.
Output specification

For each of the test cases output a single line with a single word "YES" if the candies can be distributed equally, or "NO" otherwise.
Example

Input:
2

5
5
2
7
3
8

6
7
11
2
7
3
4

Output:
YES
NO

ALGORITHM :

1. For each input , mod the sum of candy's with Number of people so that sum can be kept minimum

*/

# include <iostream>
typedef unsigned long long ullong;
using namespace std;

int main()
{
    ullong input,N,result=0,candy,itr;
    cin>>input;
    
    while(input--)
    {
        cin>>N;
        itr = N;
        result=0;
        while(itr--)
        {
            cin>>candy;
            result += candy;
            result %= N;;
        }
        if(result != 0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}
            
    

