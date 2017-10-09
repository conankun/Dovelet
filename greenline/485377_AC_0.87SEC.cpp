#include<stdio.h>
int N;
int dis[1111111];
int nu[1111111];
int r1,r2;
int min(int a,int b) {
	if(a>b) return b;
	return a;
}
int main() {
	int i,j;
	scanf("%d",&N);
	for(i=1;i<=N;i++) {
		scanf("%d",&dis[i]);
		nu[i]=nu[i-1]+dis[i];
	}
	int p=2;
	int ans=0,a=1,b=2;
	for(i=1;i<=N;i++) {
		int before = min(nu[p-1]-nu[i-1],nu[N]-nu[p-1]+nu[i-1]);
		for(j=p+1;;j++) {
			if(before >= min(nu[j-1]-nu[i-1],nu[N]-nu[j-1]+nu[i-1])) break;
			else {
				before=min(nu[j-1]-nu[i-1],nu[N]-nu[j-1]+nu[i-1]);
				p=j;
			}
			if(min(nu[j-1]-nu[i-1],nu[N]-nu[j-1]+nu[i-1]) > ans) {
				ans = min(nu[j-1]-nu[i-1],nu[N]-nu[j-1]+nu[i-1]);
				a=i;
				b=p;
			}
		}
	}
	if(a>b) {
		int temp=a;
		a=b;
		b=temp;
	}
	printf("%d\n%d %d",ans,a,b);
}