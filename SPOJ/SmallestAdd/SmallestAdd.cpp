/*
Add program with minimum size
97 is the output here
Best is 78
*/

#include<iostream>
#define s std::
main()
{
int i,a,t=0;
s cin>>i;
while(i--){s cin>>a;a<0?:t+=a;}
s cout<<t;
}

