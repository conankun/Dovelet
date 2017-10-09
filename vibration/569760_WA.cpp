#include<stdio.h>
#define MOD 1000000009
int n,D[10000];
int main() {
	scanf("%d",&n);
	int i;
	D[1]=1;D[2]=1;
	for(i=3;i<=n;i++) {
		D[i] = D[i-2]*((i*(i-1))/2-1);
	}
	printf("%d",D[n]);
}