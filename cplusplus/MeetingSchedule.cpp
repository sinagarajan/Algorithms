/*

Given M busy-time slots of N people, You need to print all the available time slots when all the N people can schedule a meeting for a duration of K minutes.
Event time will be of form HH MM ( where 0 <= HH <= 23 and 0 <= MM <= 59 ), K will be in the form minutes.

Input Format:

M K [ M number of busy time slots , K is the duration in minutes ]
Followed by M lines with 4 numbers on each line.
Each line will be of form StartHH StartMM EndHH EndMM  [ Example 9Am-11Am time slot will be given as 9 00 11 00 ]
An event time slot is of form [Start Time, End Time ) . Which means it inclusive at start time but doesn’t include the end time.
So an event of form 10 00  11 00 => implies that the meeting start at 10:00 and ends at 11:00, so another meeting can start at 11:00.

Sample Input:
5 120
16 00 17 00
10 30 14 30
20 45 22 15
10 00 13 15
09 00 11 00

Sample Output:
00 00 09 00
17 00 20 45

Sample Input:
8 60
08 00 10 15
22 00 23 15
17 00 19 00
07 00 09 45
09 00 13 00
16 00 17 45
12 00 13 30
11 30 12 30

Sample Output:
00 00 07 00
13 30 16 00
19 00 22 00

Constraints :
1 <= M <= 100

Note: 24 00 has to be presented as 00 00.

Algorithm :

1. Create an array of size 1440 which is 24 x 7 and init with 0
2. For each input schedule, book all the index of the arrays ( 00:00 01:00 -> index 0 to 59 -> 1
3. Find the length of each free time ( Number of zeroes ) and check if length is more than specified free time


*/




# include <iostream>
using namespace std;

/* Global array that contains whether a minute in a day is booked or not */

int array[1440];

/* Initialize the array to 0 */

static void initialize()
{
    int i=0;
    for(;i<1440;i++)
        array[i]=0;
}

/* Print the Free Time In the Specified Format */

void print(int start, int i,int freetime)
{
    int end,hr,min;
    end=i;
    if(((end-start))>= freetime)
        {
                hr=start/60;
                min=start%60;
                if(hr<10)
                {
                    cout<<"0"<<hr;
                }
                else
                {
                    cout<<hr;
                }
                if(min<10)
                {
                    cout<<" 0"<<min<<" ";
                }
                else
                {
                    cout<<" "<<min<<" ";
                }
                hr=end/60;
                if(hr==24) hr=0;
                min=end%60;
                if(hr<10)
                {
                    cout<<"0"<<hr;
                }
                else
                {
                    cout<<hr;
                }
                if(min<10)
                {
                    cout<<" 0"<<min<<endl;
                }
                else
                {
                    cout<<" "<<min<<endl;
                }
                hr=end/60;
                min=start%60;
            }
    }

/* Book the minutes in the global array by replacing 0 with 1 */

void book(int starthr,int startmin,int endhr,int endmin)
{
    for(int i=((starthr*60)+startmin);i < ((endhr*60)+endmin);i++)
    {
        array[i]=1;
    }
}

/* Find the Free time between the N individuals */

void findfree(int freetime)
{
    int start=-1,end,i,hr,min;

    /* For each minute, find the free time and call print function, which will print only if free time is higher */

    for(i=0;i<1440;i++)
    {
        if(array[i]==0)
        {

			/* Start is initialized only if not initialized */

            if(start==-1)
            {
                start=i;
            }
            continue;
        }
        else if (start != -1 )
        {

			/* Print only when the value of array starts to 1 and start is not -1 */

            print(start,i,freetime);
            start=-1;
        }
    }

    /* Don't leave the final free time */

    if(start != -1)
        print(start,i,freetime);
}

int main()
{
    int N,freetime,i,starthr,startmin,endhr,endmin;
    initialize();
    cin>>N;
    cin>>freetime;
    for(i=0;i<N;i++)
    {
        cin>>starthr;
        cin>>startmin;
        cin>>endhr;
        cin>>endmin;
        book(starthr,startmin,endhr,endmin);
    }
    findfree(freetime);
}