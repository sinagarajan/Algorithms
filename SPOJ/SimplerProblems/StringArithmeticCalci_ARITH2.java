/*
Input specification

The first line of the input file contains an integer T specifying the number of test cases. Each test case is preceded by a blank line.

Each test case represents one sequence of button presses for a pocket calculator. The sequence consists of non-negative integers and arithmetic operators and ends with an equal sign. It may also contain spaces to improve readability.

The operator / represents integer division, rounded down. You may assume that no test case contains division by zero and that in all test cases all intermediate results are non-negative.

Tip: long long int in C/C++, long in Java or int64 in Pascal is enough for this problem.
Output specification

For each sequence from the input file output the number that would be displayed on the calculator.
Example

Input:
4

1 + 1 * 2 =

29 / 5 =

103 * 103 * 5 =

50 * 40 * 250 + 791 =

Output:
4
5
53045
500791
*/


import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws Exception 
    {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        sc.nextLine();
        for (int testCase = 1; testCase <= N; testCase++) 
        {
            sc.nextLine();
            String string = sc.nextLine();
            string = string.replaceAll("=", "");
            String[] value = string.split("\\s+");
            BigInteger res = BigInteger.valueOf(0);
            char op = '+';
            for (String current : value) 
            {
                if (current.length() == 0) 
                {
                    continue;
                }
                if ("+".equals(current)) 
                {
                    op = '+';
                } 
                else if ("-".equals(current)) 
                {
                    op = '-';
                }
                else if ("*".equals(current)) 
                {
                    op = '*';
                }
                else if ("/".equals(current)) 
                {
                    op = '/';
                } 
                else 
                {
                    BigInteger val = new BigInteger(current);
                    switch (op) {
                        case '+':
                            res = res.add(val);
                            break;
                        case '-':
                            res = res.subtract(val);
                            break;
                        case '*':
                            res = res.multiply(val);
                            break;
                        case '/':
                            res = res.divide(val);
                            break;
                    }
                }
            }
            System.out.println(res);
            
        }
        
    }
}

