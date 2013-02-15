/*
Given a paragraph of text, write a program to find the first shortest sub-segment that contains each of the given k words at least once. A segment is said to be shorter than other if it contains less number of words.

Ignore characters other than [a-z][A-Z] in the text. Comparison between the strings should be case-insensitive.

If no sub-segment is found then the program should output “NO SUBSEGMENT FOUND”.

Input format :

First line of the input contains the text.
Next line contains k , the number of  words given to be searched.
Each of the next k lines contains a word.


Output format :

Print first shortest sub-segment that contains given k words , ignore special characters, numbers.If no sub-segment is found it should return “NO SUBSEGMENT FOUND”

Sample Input :

This is a test. This is a programming test. This is a programming test in any language.
4
this
a
test
programming

Sample Output :

a programming test This

Explanation :
In this test case segment "a programming test. This" contains given four words. You have to print without special characters, numbers so output is "a programming test This".  Another segment "This is a programming test." also contains given  four words but have more number of words.


Constraint :

Total number of character in a paragraph will not be more than 200,000.
0 < k <= no. of words in paragraph.
0 < Each word length < 15


Algorithm :

1. Replace all the special characters in the string and remove the duplicates in the input string
2. HashMap (getIndex) stores the input value

		this 0
		a	 1
		test 2
		programming 3

3. Get the input string one by one and store occuring index in another HashMap as well as ArrayList

		ArrayList[0] (occurence of 'this') 0	4	9
		ArrayList[1] (occurence of 'a')	   2	6	11
		ArrayList[2] (occurence of 'test') 3	8	13
		ArrayList[3] (occurence of 'prog') 7	12

4. Second Hashmap (mapIndex) contains mapping between occurence and index hashmap 0-0 2-1 3-2 4-0 6-1 7-3 8-2 9-0 11-1 12-3 13-2

5. For each element in the hashmap, find the neighbor occurrences

		Example: (6) nearest occurrence of 'this' 4 , 'test' 8 , 'prog' 7 . Hence , minimum = 4, maximim = 8 .Length =5

		Repeat for each and find the lowest length.

(NOTE: Second HashMap is included here so that we can find the occurrence sorted manner )


*/

import java.util.*;

public class Solution {

 public static int k;
 public static String input_string[];
 public static HashMap<String,Integer> getIndex;
 public static ArrayList<Integer>[] arrays;
 public static Map<Integer,Integer> mapIndex;

 public static int min = 200000;
 public static int max = 0;
 public static int length = 200000;

 /* Prints the output in required format */

 public static void print()
 {
     for(int i=min; i<max; i++)
     {
         System.out.print(input_string[i] + " ");
     }
     System.out.print(input_string[max]);
 }

 /* Gets the closest occurrence of the given word in each occurrences */

 public static int getNearby(int data, int level)
 {
     int tempLength=200000,tempMin=200000,temp;
     for(int i=0; i< arrays[level].size();i++)
     {
         temp=Math.abs(data - arrays[level].get(i));
         if ( temp < tempLength)
         {
              tempLength = temp;
              tempMin = arrays[level].get(i);
         }
     }
     return tempMin;
 }

 /* Calculate Minimum occurrence and Maximum occurrence of each word */

 public static void findanswer(int data, int level)
 {
     int currMin=data,currMax=data;
     for(int i=0;i< arrays.length; i++)
     {
         if(i==level) continue;
         int temp = getNearby(data , i);

         currMin = Math.min(currMin,temp);
         currMax = Math.max(currMax,temp);

         //Update only during final iteration

         if(i==(arrays.length - 1))
         {
             if(length > (currMax-currMin +1))
                {
                    length = currMax-currMin +1;
                    min = currMin;
                    max = currMax;
                }
         }
     }
 }

 public static void main(String[] args)
 {
      int j=0;
      Scanner in = new Scanner(System.in);
      String str = in.nextLine();

      //Replace all speacial characters

      str = str.replaceAll("[,|.|!|@|#|$|%|^|&|*|(|)|{|}|<|>|/|-|_|~|`|\\d]", "");
      str = str.replaceAll("( )+", " ");
      k = in.nextInt();

      //One hash maps stores the index of each input string and the other stores level of each occurrence
      getIndex = new HashMap<String,Integer>();
      mapIndex = new HashMap<Integer,Integer>();
      in.nextLine();
      input_string = str.split(" ");

      //Input the string from the user
      for(int i=0; i < k; i++)
      {
        String s = in.nextLine().toLowerCase();
        if(getIndex.get(s)== null)
        {
            getIndex.put(s, j);
            j++;
        }
       }
      arrays= new ArrayList[j];
      for(int itr=0; itr< j; itr++)
          arrays[itr]= new ArrayList<Integer>();

      int temp;

      for(int i=0; i<input_string.length; i++)
      {
          try
          {
            temp =getIndex.get(input_string[i].toLowerCase());
          }
          catch(Exception e)
          {
              continue;
          }
          arrays[temp].add(i);
          mapIndex.put(i,temp);
      }

      //No need to wait for multiple characters

      for(int i=0; i<arrays.length; i++)
      {
            if(arrays[i].size()==0)
            {
                System.out.println("NO SUBSEGMENT FOUND");
                return;
            }
      }

	  //Calls the answer for each occurrence in sorted order

      for (Integer key : mapIndex.keySet())
      {
        Integer value = mapIndex.get(key);
        findanswer(key,value);
      }

     print();
   }
}