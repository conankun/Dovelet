#include<stdio.h>
#include<math.h>
#define MOD 500000000000000007LL
unsigned long long n;
unsigned long long sum,plus=1;
int main() {
	scanf("%llu",&n);
	unsigned long long i;
	for(i=5;i<=n;i*=5) {
		sum+=plus*((unsigned long long)(n/i)-(unsigned long long)((unsigned long long)(n/i)/5));
		sum%=500000000000000007LL;
		plus++;
	}
	printf("%llu",sum);
}