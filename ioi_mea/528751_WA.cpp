#include<stdio.h>
long long n,arr[10000000];
int main() {
	scanf("%lld",&n);
	long long i;
	for(i=1;i<=n;i++) scanf("%lld",&arr[i]);
	long long s=arr[1],e=2000000000;
	for(i=2;i<=n;i++) {
		if(e>arr[i]) e=arr[i];
		long long t=arr[i]*2-e;//시작
		long long l=arr[i]*2-s;//끝
		s=t,e=l;
	}
	printf("%d",e-s+1);
}