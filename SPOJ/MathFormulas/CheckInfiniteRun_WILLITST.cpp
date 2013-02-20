/*

When Bob was in library in University of Warsaw he saw on one of facades caption :"Will it ever stop?" and below some mysterious code:

while n > 1
  if n mod 2 = 0 then
    n:=n/2
  else
    n:=3*n+3

Help him finding it out !

Input

In first line one number n<=10^14.
Output

Print "TAK" if program will stop, otherwise print "NIE"
Example

Input:
4

Output:
TAK

ALGORITHM:

1. If number is power of 2 , it will stop and check that alone

*/


# include <iostream>

typedef unsigned long long ullong;
using namespace std;

int findPower(ullong input)
{
    ullong itr=2;
    if (input < itr || (input % 2 == 1))
        return false;
    while (itr <= input)
    {
        if(input % itr == 0)
        {
            itr = itr<<1;
        }
        else 
        {
            return false;
        }
    }
    return true;
}
        

int main()
{
    ullong input;
    cin >> input ;
    if(findPower(input))
        cout<<"TAK";
    else
        cout<<"NIE";
}
    
      

