#include<stdio.h>
#define min(a,b) (a<b?a:b)
int main() {
	long long n,m;
	scanf("%lld%lld",&n,&m);
	n=n+m;
	m = min(m,n-m);
	long long i;
	long long ans=1;
	for(i=1;i<=m;i++) {
		ans=ans*(n-i+1)/i;
	}
	printf("%lld",ans);
}