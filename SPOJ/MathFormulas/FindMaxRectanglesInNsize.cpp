/*
Byteman has a collection of N squares with side 1. How many different rectangles can he form using these squares?

Two rectangles are considered different if none of them can be rotated and moved to obtain the second one. During rectangle construction, Byteman can neither deform the squares nor put any squares upon any other ones.
Input

The first and only line of the standard input contains one integer N (1 = N = 10000).
Output

The first and only line of the standard output should contain a single integer equal to the number of different rectangles that Byteman can form using his squares.
Example

For the input data:

6

the correct result is:

8

ALGORITHM :

1. For each integer till N (given value)
2. Calculate all the factors of N until factor*factor is equal to N

ie Example : 2

1 is factor [1x1 <=2]
2 is not considered [2x2 > 2]. Exit . Sum=1

Example: 4

1 is factor [1x1 <= 4]
2 is factor [2*2 <=4]
3 is not considered [3*3 > 4] . Exit . Sum =2

*/

# include <iostream>
# include <math.h>
using namespace std;

int findMaxRectangle(int input)
{
    int result = 1;
    for(int start = 2 ; start * start <= input; ++start)
    {
        if(input % start == 0)
            ++result;
    }
    return result;
}

int main()
{
    int input,sum=0;
    cin>>input;
    for(int i=1; i<= input; i++)
    {
        sum+=findMaxRectangle(i);
    }
    cout<<sum;
}
        

