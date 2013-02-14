/**

Given a number K, find the smallest Fibonacci number that shares a common factor( other than 1 ) with it. A number is said to be a common factor of two numbers if it exactly divides both of them. 
 
Output two separate numbers, F and D, where F is the smallest fibonacci number and D is the smallest number other than 1 which divides K and F.
 
Input Format 
 
First line of the input contains an integer T, the number of testcases.
Then follows T lines, each containing an integer K.
 
Output Format
 
Output T lines, each containing the required answer for each corresponding testcase.
 

 

 

Sample Input 
 
3
3
5
161
 
Sample Output
 
3 3
5 5
21 7
 
Explanation
 
There are three testcases. The first test case is 3, the smallest required fibonacci number  3. The second testcase is 5 and the third is 161. For 161 the smallest fibonacci numer sharing a common divisor with it is 21 and the smallest number other than 1 dividing 161 and 7 is 7.
 
Constraints :
 
1 <= T <= 5
2 <= K <= 1000,000
The required fibonacci number is guranteed to be less than 10^18.


*/


/* JAVA PROGRAM */



import java.io.*;

public class Solution {

/* Compute final answer */
    
private static void findanswer(long data)
{

    /* Initialization */

    int sqroot= (int)Math.sqrt(data),flag,itr=0;
    long[] array=new long[sqroot];
    long div=2;
    long temp,sum;

    /* Find All the Factors of Random Number */

    while(div <= data)
    {
        if( data % div == 0)
        {
            array[itr++]=div;
        }
        div++;
    }
    div=0;
    sum=1;
    flag=0;

    /* Check for each fibonacci number , if it is divisble by the factors found in earlier step */

    while(true)
    {
        temp=sum;
        sum+=div;
        div=temp;
        for(int i=0;i<itr;i++)
        {
            if(sum % array[i] == 0)
            {
                System.out.println(sum+" "+array[i]);
                flag=1;
                break;
            }
        }
        if(flag==1)break;
    }
}

    public static void main(String args[] ) throws Exception 
     {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int N = Integer.parseInt(line);
        long[] array=new long[N];
        for (int i = 0; i < N; i++) 
        {
                    line = br.readLine();
                    array[i] = Long.parseLong(line);
        }
         for (int i = 0; i < N; i++) 
        {
            findanswer(array[i]);
        }
    }
}