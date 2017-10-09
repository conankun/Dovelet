#include<stdio.h>
int n;
double sum=0.00;
int main() {
	scanf("%d",&n);
	int i;
	sum=1;
	for(i=1;i<=n;i++) {
		sum*=1.00/365.00;
	}
	for(i=1;i<=n;i++) {
		sum*=(365-i+1);
	}
	printf("%.6lf",1-sum);
}