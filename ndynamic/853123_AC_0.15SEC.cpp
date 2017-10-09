#include<stdio.h>
#define MOD 1000000009
long long N;
void process() {
	long long A=N;
	if(N%2==1) A++;//type A
	long long K=A/2;

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
	
	if(N%2==1) K=N;
	else K=N+1;
	agent=result;
	long long fresult=1;
	for(;K>0;K/=2) {
		if(K%2==1) {
			fresult*=agent;
			fresult%=MOD;
		}
		agent*=agent;
		agent%=MOD;
	}
	printf("%lld",fresult);
}
int main() {
	scanf("%lld",&N);
	process();
}