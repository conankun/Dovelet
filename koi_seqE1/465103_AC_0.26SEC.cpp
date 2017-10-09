#include<stdio.h>
int p[100011],n,k;
int main() {
	scanf("%d%d",&n,&k);
	int i,s=0;
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	for(i=1;i<=k;i++) {
		s+=p[i];
	}
	int mx=s;
	for(i=k+1;i<=n;i++) {
		s+=p[i];
		s-=p[i-k];
		if(s > mx) mx = s;
	}
	printf("%d",mx);
}