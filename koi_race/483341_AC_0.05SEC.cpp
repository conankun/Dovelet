#include<stdio.h>
int dis[1111][1111];
int dp[1111];
int back[1111];
int last[1111];
int IN[1111];
int N,M;
int topo[1111];
int ind;
int main() {
	scanf("%d%d",&N,&M);
	int p,q,r;
	int i,j;
	for(i=1;i<=M;i++) {
		scanf("%d%d%d",&p,&q,&r);
		dis[p][q]+=-r;
		if(q!=1) IN[q]++;
		else last[p]=1;
	}
	p=1;
	topo[++ind]=p;
	IN[1]=-1;
	for(i=1;i<=N;i++) {
		for(j=1;j<=N;j++) {
			if(dis[p][j]<0) {
				IN[j]--;
			}
		}
		for(j=1;j<=N;j++) {
			if(IN[j]==0) {
				IN[j]=-1;
				topo[++ind]=j;
				p=j;
				break;
			}
		}
	}
	int index=1;
	for(i=1;i<=ind;i++) {
		p = topo[i];
		for(j=1;j<=N;j++) {
			if(dp[j]>dp[p]+dis[p][j] && dis[p][j]<0) {
				dp[j]=dp[p]+dis[p][j];
				back[j]=p;
				if(last[p]) {
					index = p;
				}
			}
		}
	}
	printf("%d\n",dp[1]*-1);
	int path[1000];
	int indx=0;
	path[++indx]=index;
	while(index > 1) {
		index = back[index];
		if(index > 1) path[++indx]=index;
	}
	printf("1 ");
	for(i=indx;i>=1;i--) printf("%d ",path[i]);
	printf("1");
}