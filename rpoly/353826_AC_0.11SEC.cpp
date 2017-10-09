#include <stdio.h>
#include <cmath>
int main () {
    double r,n;
    scanf("%lf %lf",&r,&n);
    printf("%.3f",n*r*r*sin(2*acos(-1)/n)/2);
}