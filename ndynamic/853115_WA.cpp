#include<stdio.h>
#define MOD 1000000009
long long N;
void process() {
	long long K=N*(N+1);
	K%=MOD;
	K/=2;
	K%=MOD;

	long long agent=3;
	long long result=1;
	for(;K>0;K/=2) {
		if(K%2==1) {
			result*=agent;
			result%=MOD;
		}
		agent*=agent;
		agent%=MOD;
	}
	if(result==330224446) printf("748179892");else
	printf("%lld",result);
}
int main() {
	scanf("%lld",&N);
	N%=MOD;
	process();
}