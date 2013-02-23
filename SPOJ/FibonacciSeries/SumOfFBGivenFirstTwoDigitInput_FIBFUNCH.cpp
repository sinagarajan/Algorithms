/*

Fibonacci series is a series in which every element is sum of previous 2 elements.

first 2elements are 0,1 and the series goes like 0,1,1,2,3,5,8,13 ........

 

What if you were given 2 random numbers as the starting of the series and u follow the same rule as the fibonacci rule.

for eg. if you were given 2 and 2 .. the series would become

2 2 4 6 10 16 26 .........

 

Now ur task is Simple ...

You will be given 2 numbers a & b .. the first and second term of the series..

you need to calculate the sum of first n numbers of the series so formed..

Since the numbers can be big you need to print the result mod some number 'M' provided in the input.

Input

first line will have single number 't' - number of test cases.

each test case will have 4 numbers a,b,n & M

a- first number of the series

b- second number of the series

n- calculate the sum till n numbers

M- print the result mod M

Output

single number for each case - sum of n terms mod M

Example

Input:
2
2 2 10 21
1 3 10 21

 Output:
13
4

Explanation - for first case series is 2 2 4 6 10 16 26 42 68 110 .. Sum is 286.. o/p = 286%21 = 13

NOTE -
Number of test cases <=100.
0 <= a,b<= 10^8

ALGORITHM :

1. See the other program to find fibonacci 
2. In this case, it is required to calculate sum of n elements and not sum of two elements 
3. Hence Fib(N+2) - Fib(1) gives answer 
4. Calculate Fib(N+1) and multiply it with F(1) -> Created based on input first two elements -> will provide 	Fib(N+2)

*/


# include <iostream>
# include <string.h>
typedef long long llong;
using namespace std;



void multiply(llong first[2][2], llong second[2][2], llong modval)
{
    llong temp[2][2];
    temp[0][0] = (first[0][0] * second[0][0] + first[0][1] * second[1][0]) % modval ;
    temp[0][1] = (first[0][0] * second[0][1] + first[0][1] * second[1][1]) % modval ;
    temp[1][0] = (first[1][0] * second[0][0] + first[1][1] * second[1][0]) % modval ;
    temp[1][1] = (first[1][0] * second[0][1] + first[1][1] * second[1][1]) % modval ;
    memcpy(first,temp,sizeof(temp));
}

llong fibo(llong input,llong start,llong end,llong modval)
{
    llong result[2][2]={{1, 0}, {0, 1}},current[2][2] = {{1, 1}, {1, 0}}, final[2][2]={{start+end,end},{end,start}};
        
    --input;
    --input;
           
    while( input > 0 )
    {
        if(input & 1)
        {
            multiply(result,current,modval);
        }
        input>>=1;
        multiply(current,current,modval);
    }

    multiply(result,final,modval);
   
    return result[0][1];
    
}
int main()
{
    int size;
    llong start,end,sum,first,second,N,modval;
    cin>>size;
    for(int i=0; i<size; ++i)
    {
        cin>>start;
        cin>>end;
        cin>>N;
        cin>>modval;
        first = fibo(N+2,start,end,modval);
        second = end;
        sum = (first-second ) % modval;
        if(sum < 0)
        {
            sum+=modval;
        }
        cout<<sum<<endl;
    }
}

