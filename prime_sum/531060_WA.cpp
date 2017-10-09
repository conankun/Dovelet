#include<stdio.h>
#define MOD 123456789LL
long long n,primes[100000],D[1000],ind,C[1000];
int main() {
	scanf("%lld",&n);
	D[0]=1;
	C[0]=1;
	long long i,j;
	for(i=2;i<=n;i++) {
		bool tr=1;
		for(j=2;j*j<=i;j++) {
			if(i%j==0) {
				tr=0;
				break;
			}
		}
		if(tr) primes[++ind]=i;
	}
	for(i=1;i<=ind;i++) {
		for(j=n;j>=0;j--) {
			if(C[j]>0) {
				if(j+primes[i]<=n) {
					D[j+primes[i]]+=D[j];
					D[j+primes[i]]%=MOD;
					C[j+primes[i]]=1;
				}
			}
		}
	}
	printf("%lld",D[n]);
}