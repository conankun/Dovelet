#include<stdio.h>
#define MOD 100000000
int main() {
	long long n;
	scanf("%lld",&n);
	long long i;
	long long ans=0;
	for(i=1;i<=n;i++) {
		long long m=i;
		long long mn=1;
		long long g=i;
		for(;m;m>>=1) {
			if(m&1) {
				mn*=g;
				mn%=MOD;
			}
			g*=g;
			g%=MOD;
		}
		ans+=mn;
		ans%=MOD;
	}
	printf("%08lld",ans);
}