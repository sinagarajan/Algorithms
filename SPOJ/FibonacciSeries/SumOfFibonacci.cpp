/*

The fibonacci sequence is defined by the following relation:

F(0) = 0

F(1) = 1

F(N) = F(N - 1) + F(N - 2), N >= 2

 

Your task is very simple. Given two non-negative integers N and M, you have to calculate the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.
Input
The rst line contains an integer T (the number of test cases). Then, T lines follow. Each test
case consists of a single line with two non-negative integers N and M.

 

The first line contains an integer T (the number of test cases). Then, T lines follow. Each test case consists of a single line with two non-negative integers N and M.
Output

For each test case you have to output a single line containing the answer for the task.
Example

Input:
3
0 3
3 5
10 19

Output:
4
10
10857

Constraints

    T <= 1000
    0 <= N <= M <= 109


ALGORITHM:

Facts.

1. Fib(0) =0 ; Fib(1) =1;
2. Sum of Fib(n) = (Fib(n+2) - 1) -> Fib(1)
3. Sum of Fib( n to m) = Fib(m+2) - Fib(n+1)

Matrix Expo :

1 1	1 1
1 0  *  1 0  is Fib(2)

Fib(2) * Fib(2) is Fib(4)

	  1 1
Fib(4) *  1 0 is Fib(5)


Fib(n+1)  Fib(n)
Fib(n)	  Fib(n-1)


Example : 13

Multiply 1 2 4 8 Max . So 13-8 = 3. 

or

Do conversion from decimal to binary .
Result array will always contain updated value

Ex 5 and 6  101 and 110

1 is added to 4 and 2 is added to 4

*/



# include <iostream>
# include <string.h>
typedef long long llong;
using namespace std;

const long long MOD = 1000000007;

void multiply(llong first[2][2], llong second[2][2])
{
    llong temp[2][2];
    temp[0][0] = (first[0][0] * second[0][0] + first[0][1] * second[1][0]) % MOD ;
    temp[0][1] = (first[0][0] * second[0][1] + first[0][1] * second[1][1]) % MOD ;
    temp[1][0] = (first[1][0] * second[0][0] + first[1][1] * second[1][0]) % MOD ;
    temp[1][1] = (first[1][0] * second[0][1] + first[1][1] * second[1][1]) % MOD ;
    memcpy(first,temp,sizeof(temp));
}

llong fibo(llong input)
{
    llong result[2][2]={{1, 0}, {0, 1}},current[2][2] = {{1, 1}, {1, 0}};
        
    --input;
        
    while( input > 0 )
    {
        if(input & 1)
        {
            multiply(result,current);
        }
        input>>=1;
        multiply(current,current);
    }
    
    return result[0][0];
    
}
int main()
{
    int size;
    llong start,end,sum,first,second;
    cin>>size;
    for(int i=0; i<size; ++i)
    {
        cin>>start;
        cin>>end;
        first = fibo(end+2);
        second = fibo(start+1);
        sum = (first-second ) % MOD;
        if(sum < 0)
        {
            sum+=MOD;
        }
        cout<<sum<<endl;
    }
}

