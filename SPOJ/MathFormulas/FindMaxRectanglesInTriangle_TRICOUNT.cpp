/*
Input

The first line of the input contains an integer T (T = 10000) - the number of test cases and T lines follow. Each line contains an integer N (1 = N = 106) which is the level of the triangle in that test case.
Output

For each test case, you should write a seperate line: the number of triangles in the biggest one (Level N). (All answers will fit within the range of a 64-bit integer)
Example

Input:
3
1
2
3

Output:
1
5
13


ALGORITHM:

1. (input*(input+2)*(2*input+1))/8
*/

# include <iostream>
typedef long long llong;
using namespace std;
int main()
{
    int size;
    llong input;
    cin>>size;
    while(size--)
    {
        cin>>input;
        cout<<((input*(input+2)*(2*input+1))/8)<<endl;
    }
}

