#include<stdio.h>
long long min(long long a,long long b) {
	if(a<b) return a;
	return b;
}
int main() {
	long long a,b;
	scanf("%lld%lld",&a,&b);
	printf("%lld",min(a,b));
}