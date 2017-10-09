#include<stdio.h>
#include<math.h>
long long a,b,ans,g=1;
int main() {
	scanf("%lld%lld",&a,&b);
	int i;
	for(i=a+1;i<=62;i++) {
		int k=pow(2.,i);
		while(1) {
			if(k/10 == 0) break;
			k/=10;
		}
		if(k==b) {
			ans=i;
			break;
		}
	}
	printf("%d",ans);
}