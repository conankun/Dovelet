#include<stdio.h>
int L,N,p,k;
int cake[10000];
int main() {
	scanf("%d%d",&L,&N);
	int i,j;
	int mx=0,pp=0;
	int max2=0,ppp;
	for(i=1;i<=N;i++) {
		int cnt=0;
		scanf("%d%d",&p,&k);
		if(k-p>max2) {
			max2=k-p;
			ppp=i;
		}
		for(j=p;j<=k;j++) {
			if(cake[j]==0) {
				cnt++;
				cake[j]=i;
			}
		}
		if(cnt > mx) {
			mx=cnt;pp=i;
		}
	}
	printf("%d\n%d",ppp,pp);
}