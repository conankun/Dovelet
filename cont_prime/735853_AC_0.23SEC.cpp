#include<stdio.h>
int n,k,cnt;
int primes[600000],prime[100000];
int main() {
	scanf("%d%d",&n,&k);
	int i,j;
	primes[1]=1;
	for(i=2;i<=n;i++) {
		for(j=2;j*i<=n;j++) {
			primes[i*j]=1;
		}
	}
	for(i=2;i<=n;i++) {
		if(primes[i]==0) prime[++cnt]=i;
	}
	for(i=1;i<=cnt-k+1;i++) {
		int sum=0;
		for(j=0;j<k;j++) {
			sum+=prime[i+j];
		}
		if(sum==n) {printf("yes");return 0;}
	}
	printf("no");
}