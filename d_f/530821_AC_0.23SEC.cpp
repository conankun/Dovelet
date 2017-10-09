#include<stdio.h>
double d;
int main() {
	scanf("%lf",&d);
	int a=(int)d;
	if(a>=0) printf("%d %.2lf ",a,d-a);
	else printf("%d %.2lf",a-1,d-a+1);
	
}