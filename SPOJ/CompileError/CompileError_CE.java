/*
You are to write a program to analyse some simple arithmetical expressions. The BNF form of the defination of the expression is below.

<expression>::=<num><oper><num>
<num>::=0|1|2|...|99
<oper>::=+|-|*

Tip: You may find this problem is like the problem GALAXY very much. You may use any language you like to solve this problem.
Input

Exactly 99 test cases.

Each test case contains one line with a correct expression, without leading or trailing spaces.
Output

For each test case you should output one line contains the result of the expression without any leading zeros. You may assume this number is always a non-negative one.
Score

Score is the length of your source.
Example

Input:
6*7
67-25
31+11
[And 96 test cases more.]

Output:
42
42
42
[And 96 test cases more.]
n
*/

import java.io.*;
import java.util.*;

class Solution {
    
    public static String value[];
        
    public static void main(String args[] ) throws Exception {
        
        Scanner sc = new Scanner(System.in);;
        String expr;
        int val1,val2;
        while(sc.hasNextLine())
        {
            expr=sc.nextLine();
            expr = expr.replaceAll(" ","");
            if(expr.indexOf("+") != -1)
            {
                expr = expr.replaceAll("\\+", " ");
                value = expr.split(" ");
                System.out.println(Integer.parseInt(value[0]) + Integer.parseInt(value[1]));
                continue;
            }
            
            if(expr.indexOf("-") >= 0)
            {
                String[] value  = expr.split("-");
                System.out.println(Integer.parseInt(value[0]) - Integer.parseInt(value[1]));
                continue;
            }
            
            if(expr.indexOf("*") >= 0)
            {
                expr = expr.replaceAll("\\*", " ");
                value = expr.split(" ");
                System.out.println(Integer.parseInt(value[0]) * Integer.parseInt(value[1]));
                continue;
            }
        }        
    }
}