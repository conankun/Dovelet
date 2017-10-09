#include<stdio.h>
int N;
struct A {
	int a,b;
}tem[1111111];
int main() {
	scanf("%d",&N);
	int i,j;
	for(i=1;i<=N;i++) scanf("%d%d",&tem[i].a,&tem[i].b);
	int p=tem[N].b,len=1;
	int ans=1;
	for(i=N-1;i>=1;i--) {
		if(tem[i].b < p) {
			p=tem[i].b;
			len++;
			if(len > ans) ans = len;
		} else if(tem[i].a <= p && tem[i].b >= p) {
			len++;
			if(len > ans) ans = len;
		} else {
			p=tem[i].b;
			len=1;
		}
	}
	printf("%d",ans);
}