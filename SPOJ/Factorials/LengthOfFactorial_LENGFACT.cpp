
/*
Length of the factorial

This is a Copy paste from Internet called Stirling's Approximation

*/


#include <cmath>
#include <cstdio>
using namespace std;

int main() {
double result, ans, pi = acos(-1.0);
int tests;
scanf("%d", &tests);
while(tests--) {
scanf("%lf", &result);
// striling's approximation
if(result<3.0) ans = 1.0;
else ans = floor((result*log(result)-result+(log(2.0*pi*result))/2.0)/log(10.0))+1.0;
printf("%.0lf\n", ans + 1e-12);
}
return 0;
}