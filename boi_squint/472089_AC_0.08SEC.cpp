#include<stdio.h>
#include<math.h>
long long n;
int main() {
scanf("%lld",&n);
double s = sqrt((double)n);
printf("%.0lf",ceil(s));
}