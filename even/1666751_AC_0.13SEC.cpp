#include<stdio.h>
#include<cmath>
int main (void)
{
int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",(b-a+1)-(int)sqrt(b)+(int)sqrt(a-1));
}