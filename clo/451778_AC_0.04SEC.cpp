#include<stdio.h>
int n;
int main() {
	scanf("%d",&n);
	if(n==12) n=0;
	if((n*30)/5.5 >= 60.0000000) printf("CAN'T SEE!");
	else printf("%.6lf",(n*30)/5.5);
}