/*
We call a string S magical if every substring of S appears in Galadriel's Mirror (under lateral inversion). In other words, a magical string is a string where every substring has its reverse in the string.

Given a string S, determine if it is magical or not.

 

Input (STDIN):

The first line contains T, the number of test cases. The next T lines contain a string each. 

 

Output (STDOUT):

For each test case, output "YES" if the string is magical, and "NO" otherwise.

 

Constraints:

1 <= T <= 100

1 <= |S| <= 10

S contains only lower-case characters.

 

Sample Input:

2

aba

ab

 

Sample Output:

YES

NO


ALGORITJHM

1. Start from both the end and compare
2. Break if the pointers to start and end crosses.
3. Simple Palindrome

*/

# include <iostream>
# include <string>

using namespace std;

int main()
{
    int tests,size;
    bool flag;
    string s ;
    cin>>tests;
    for(int i=0; i< tests; i++)
    {
        cin >> s;
        size = s.size();
        flag=true;
        for(int i=0,j=size-1; i<=j; j--,i++)
        {
            if(s[i] != s[j])
            {
                flag=false;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
           
        
    }
}

