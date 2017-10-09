#include<stdio.h>
int n,m,i;
int main() {
	scanf("%d%d",&n,&m);
	int g=1;
	int cnt=0;
	while(g<=n) {cnt++;g*=m;}
	g/=m;
	int sum=0;
	int before=0;
	for(i=g;i>=1;i/=m,cnt--) {
		int now=n/g-before;
		sum+=cnt*now;
		before+=now;
	}
	printf("%d",sum);
}