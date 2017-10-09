#include<stdio.h>
#include<math.h>
#define MOD 500000000000000007LL
long long n;
long long before[999999];
long long sum,plus=1;
int main() {
	scanf("%lld",&n);
	long long i;
	for(i=5;i<=n;i*=5) {
		sum+=plus*(n/i-((n/i)/5));
		sum%=MOD;
		plus++;
	}
	printf("%lld",sum);
}