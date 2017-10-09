#include<stdio.h>
int n;
int main() {
	scanf("%d",&n);
	int i;
	int sum=0;
	for(i=1;i<=n;i++) {
		sum+=i;
		printf("1..%d %d\n",i,sum);
	}
}