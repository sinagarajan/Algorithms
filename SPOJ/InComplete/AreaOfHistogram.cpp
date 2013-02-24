# include <iostream>
# include <string.h>
# include <stack>
typedef unsigned long long ullong;
using namespace std;


int main()
{
    int tests,i,max,length,itr;
    stack<ullong> s;
    stack<int> si;
    ullong array[100001],input;
    while(1)
    {
        cin>>tests;
        length = 0;
        max=0;
        memset(array,-1,sizeof(array));
        if(!tests)
            break;
        for(i=0; i<tests; ++i)
        {
            cin>> array[i];
        }
        for(i=0; i<tests; ++i)
        {
            if(s.empty() || s.top() < array[i])
            {
                s.push(array[i]);
                si.push(i);
            }
            else
            {
                while(s.top() > array[i])
                {
                    itr = si.top();
                    max = (s.top() * (i-si.top()) < max) ? :s.top() * (i-si.top());
                           s.pop(); 
                           si.pop();
                }
                si.push(itr);
                s.push(array[i]);
            }
            
        }
        if(!s.empty())
        {
            max = (s.top() * (i-si.top()) < max) ? :s.top() * (i-si.top());
        }
        cout<<max<<endl;
    }
}
            

