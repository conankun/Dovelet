#include<stdio.h>
#include<math.h>
int main() {
    int n;
    scanf("%d",&n);
    printf("%.0lf %.0lf",ceil(n/2.0),ceil((n-n%3)/3.0)+1);
}