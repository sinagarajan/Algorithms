/* 

Note the same program will not be working for the programming languages with pre-defined data type .

Find those programs in the same folder

*/

def f(n):  
    if n == 0:  
        return 1  
    else:  
        return n * f(n-1)  
  
for t in range(0, input()):  
    print "%d" % f(input())

