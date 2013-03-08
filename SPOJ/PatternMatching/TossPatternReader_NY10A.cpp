/*
For this problem, you will write a program that implements a variation on the Penney Game.  You willread a sequence of 40 coin tosses and determine how many times each three-coin sequence appears.  Obviously there are eight such three-coin sequences: TTT, TTH, THT, THH, HTT, HTH, HHT and HHH. Sequences may overlap.  For example, if all 40 coin tosses are heads, then the sequence HHH appears 38 times.
Input

The first line of input contains a single integer P, (1 = P = 1000), which is the number of data sets that follow.  Each data set consists of 2 lines.  The first line contains the data set number N.  The second line contains the sequence of 40 coin tosses.  Each toss is represented as an upper case H or an upper case T, for heads or tails, respectively.  There will be no spaces on any input line.
Output

For each data set there is one line of output.  It contains the data set number followed by a single space, followed by the number of occurrences of each three-coin sequence, in the order shown above, with a space between each one.  There should be a total of 9 space separated decimal integers on each output line.
Example

Input:
4
1
HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
2
TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
3
HHTTTHHTTTHTHHTHHTTHTTTHHHTHTTHTTHTTTHTH
4
HTHTHHHTHHHTHTHHHHTTTHTTTTTHHTTTTHTHHHHT

Output:
1 0 0 0 0 0 0 0 38
2 38 0 0 0 0 0 0 0
3 4 7 6 4 7 4 5 1
4 6 3 4 5 3 6 5 6

ALGORITHM :

1. Store in the array 
2. 0 | H = 1
   10 | H = 11
   110 | T = 110
   1100 | H = 1101
   11010 | H = 11011

   Now AND each time with 7 to increment appropriate count array

*/

# include <stdio.h>
# include <string.h>
int main()
{
    int tests,id,hold,count[8];
    char str[50];
    scanf("%d",&tests);
    while(tests--)
    {
        scanf("%d",&id);
        scanf("%s",str);
        memset(count , 0 , sizeof(count));
        hold=0;
        for(int i=0 ; i< 40; ++i)
        {
            hold = ((hold << 1) | (str[i] == 'H'));
            if( i > 1)
            {
                count[hold & 7] +=1;
            }
        }
        printf("%d",id);
        for(int i=0; i<8; ++i)
            printf(" %d",count[i]);
        printf("\n");
    }
}

