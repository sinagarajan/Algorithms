/* Program to find the factorial of numbers ranging from 1 to 100 */

/* 

NOTE: What's tough in finding factorial ?

Yes it's tough since you can't accomodate 150 digits in a single data type . So here's the algorithm 

1. Have an array that can accomodate the length of digits in n!
2. Ex: 153 will have a[0] = 3 ; a[1] = 5 ; a[2] = 1 ; 
3. With initial input as 1, multiply each number from 1..n 

*/
# include <iostream>

using namespace std;

/*

Normal factorial program using recursion 

double factorial(double data)
{
    if(data == 0)
            return 1;
    
    return data*factorial(data-1);
}

*/

// Multiply each digit with the input argument 1..n and store the length of the array

void multiply(int array[200],int &length, int input)
{
    int temp=0,i;
    for( i=0; i<length; i++)
    {
        temp = (array[i]*input)+temp;
        array[i]=temp%10;
        temp/=10;
    }
    
    //Store remaining length of temp which need not be added with earlier digits
    
    while(temp>0)
    {
        array[i]= temp%10;
        temp/=10;
        length++;
        i++;
    }

}

// For each 1..n , call the multiply to find and store the multiplication

void factorial(int input)
{
    int array[200], length=1;
    
    // This will take care even if input is to find 0!
    
    array[0]=1;
    
    for(int i=1; i<=input; i++)
    {
         multiply(array,length,i);
    }
    
    for(int i=(length-1) ; i>=0 ; --i )
    {
        cout<<array[i];
    }

    cout<<endl;
    return;      
        
}

int main()
{
    int size;
    int input;
    cin>>size;
    for(int i=0; i<size;i++)
    {
        cin>>input;
        factorial(input);
    }
}
    