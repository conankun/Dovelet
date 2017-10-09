/*#include<stdio.h>
int n;
struct A {
	int a,b;
}tem[1111111];
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d%d",&tem[i].a,&tem[i].b);
	int ans=1;
	for(i=1;i<=n;i++) {
		int h=tem[i].a;
		for(j=i+1;j<=n;j++) {
			if(h<tem[j].a) h = tem[j].a;
			else if(h>tem[j].b) {
				if(j-i > ans) ans = j-i;
				break;
			}
		}
	}
	printf("%d",ans);
}
*/#include<stdio.h>
#include<map>
#include<algorithm>
int N;
struct A {
	int a,b;
}tem[1111111];
int D[1111111];
int main() {
	scanf("%d",&N);
	int i,j;
	int cnt=0;
	for(i=1;i<=N;i++) {
		scanf("%d%d",&tem[i].a,&tem[i].b);
	}
	int p=1,ans=0;
	for(i=1;i<=N;i++) {
		if(D[i] < 1) D[i]=1;
		if(p<i)p=i;
		for(j=p+1;j<=N;j++) {
			if(tem[j].a < tem[i].a && tem[i].a <= tem[j].b) {
				if(j==N) {
					p=j;
					if(D[i]+j-i > D[j]) D[j] = D[i]+j-i;
					if(D[j] > ans) ans = D[j];
					break;
				}
				continue;
			} else if(tem[i].a <= tem[j].a) {
				p=j;
				if(D[i]+j-i > D[j]) D[j] = D[i]+j-i;
				if(D[j] > ans) ans = D[j];
				break;
			} else break;
		}
	}
	printf("%d",ans);
}