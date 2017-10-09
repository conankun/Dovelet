#include<stdio.h>
int n;
int main() {
	scanf("%d",&n);
	int m=2*n-1;
	int sum=0;
	int i;
	for(i=1;i<=2*n-1;i+=2) {
		sum+=i*m;
		m-=2;
	}
	printf("%d",sum);
}