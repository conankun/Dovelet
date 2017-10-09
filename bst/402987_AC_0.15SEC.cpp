#include<stdio.h>
int main() {
	long long n;
	long long mn,mx;
	scanf("%lld",&n);
	mx=mn=n;
	while((mn&-mn)/2 >= 1) {
		mn=mn+((mn&-mn)/2)-(mn&-mn);
	}
	while((mx&-mx)/2 >= 1) {
		mx=mx+(mx&-mx)/2;
	}
	printf("%lld %lld",mn,mx);
}