#include<stdio.h>
#include<math.h>
#define MOD 500000000000000007LL
unsigned long long n;
unsigned long long before[999999];
unsigned long long sum,plus=1;
int main() {
	scanf("%llu",&n);
	unsigned long long i;
	for(i=5;i<=n;i*=5) {
		sum+=plus*(n/i-((n/i)/5));
		sum%=MOD;
		plus++;
	}
	printf("%llu",sum);
}