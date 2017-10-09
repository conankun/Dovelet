#include<stdio.h>
#define min(a,b) (a<b?a:b)
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	n=n+m;
	m = min(m,n-m);
	int i;
	int ans=1;
	for(i=1;i<=m;i++) {
		ans=ans*(n-i+1)/i;
	}
	printf("%d",ans);
}