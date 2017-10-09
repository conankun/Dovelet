#include<stdio.h>
int main() {
	int cnt=0;
	int n,k;
	scanf("%d%d",&n,&k);
	int i,sum=0;
	for(i=1;i<=k;i++) {
		sum+=i;
	}
	if(sum%15==0) cnt++;
	for(i=k+1;i<=n;i++) {
		sum+=i;
		sum-=(i-k);
		if(sum%15==0) cnt++;
	}
	printf("%d",cnt);
}