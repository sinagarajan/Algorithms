/*
f(n) is defined as: f(n) = 13+23+33+...+n3, so it is the sum of the cubes of all natural numbers up to n.

In this problem you are about to compute,

f(1) + f(2) + f(3) + ... + f(n)
Input

The first line is an integer T(1 = T = 100,000), denoting the number of test cases. Then, T test cases follow.

For each test case, there is an integer n(1 = n = 1,000,000) written in one line.
Output

For each test case output the result of the summatory function described above.

Since this number could be very large, output the answer modulo 1,000,000,003.
Example

Input:
3
2
10
3

Output:
10
7942
46

ALGORITHM :

1. Dynamically store all computed values in array 
2. Access the final value in O(1)

*/



#include <cstdio>

typedef long long ullong;

const int MOD = 1000000003;

inline ullong mod(ullong input) {
return input < MOD ? input : input % MOD;
}

int main() {
int test, i;
ullong sum=0, n ,array[1000001], temp;
array[0]=0;
scanf("%d", &test);

for(ullong i=1 ; i<1000001; ++i)
{
    temp = mod(mod(i*i)*i);
    sum += temp;
    array[i] = mod(array[i-1]+sum);
}

while(test--) 
{
scanf("%lld", &n);
printf("%lld\n",array[n]);
}
return 0;
}

