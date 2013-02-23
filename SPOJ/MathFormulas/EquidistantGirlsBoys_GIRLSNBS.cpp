/*
There are G girl students and B boy students in a class that is about to graduate. You
need to arrange them in a single row for the graduation. To give a better impression of
diversity, you want to avoid having too many girls or too many boys seating consecutively.
You decided to arrange the students in order to minimize the gender regularity. The
gender regularity of an arrangement is the maximum number of students of the same
gender (all girls or all boys) that appear consecutively.
Given G and B, calculate the minimum gender regularity among all possible arrange-
ments.
Input

Each test case is described using a single line. The line contains two integers G and B
representing the number of girls and boys in the class, respectively (0 = G, B = 1000).
The end of input is indicated with a line containing the number -1 twice.
Output

For each test case, output a single line with a single integer representing the minimum
gender regularity that an arrangement of G girls and B boys can have.
Example

Input: 
10 10
5 1
0 1000
-1 -1

Output: 
1
3
1000

ALGORITHM

1. MAX+MIN / MIN+1

*/

# include <iostream>
using namespace std;

int main()
{
    int girls,boys,max,min;
    while(1)
    {
        cin>>girls;
        cin>>boys;
        
        if(girls == -1 && boys == -1)
            break;
        max = std::max(girls,boys);
        min = std::min(girls,boys);
        
        cout<<((max+min)/(min+1))<<endl;
    }
}

