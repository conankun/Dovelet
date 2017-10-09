#include<stdio.h>
#include<math.h>
long long a,b,ans,g=1;
int main() {
	scanf("%lld%lld",&a,&b);
	long long i;
	for(i=a+1;i<=62;i++) {
		long long k=pow(2.,(double)i);
		while(1) {
			if(k/10 == 0) break;
			k/=10;
		}
		if(k==b) {
			ans=i;
			break;
		}
	}
	printf("%lld",ans);
}