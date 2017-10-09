#include<stdio.h>
#include<algorithm>
long long n,size[2000],p[2000];
long long dp[501][100000];
int main() {
	scanf("%lld",&n);
long long i,j;
	for(i=1;i<=n;i++) scanf("%lld",&p[i]);
	std::sort(p+1,p+1+n);
	long long pp=0,ans=-1;
	for(i=1;i<=n;i++) {
		if(pp+1 < p[i]) {
			ans=pp+1;
			break;
		} else pp+=p[i];
	}
	if(ans==-1) ans=pp+1;
	printf("%lld",ans);
}