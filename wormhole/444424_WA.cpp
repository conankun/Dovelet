#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int F,N,M,W;
int dp[1000];
struct A {
	int s,e,t;
}edge[10000];
int main() {
	scanf("%d",&F);
	int d,i,j,k;
	for(d=1;d<=F;d++) {
		for(i=0;i<=500;i++) dp[i]=99999999;
		scanf("%d%d%d",&N,&M,&W);
		for(i=1;i<=M;i++) {
			scanf("%d%d%d",&edge[i*2-1].s,&edge[i*2-1].e,&edge[i*2-1].t);
			edge[i*2].s = edge[i*2-1].e;
			edge[i*2].e = edge[i*2-1].s;
			edge[i*2].t = edge[i*2-1].t;
		}
		for(i=1;i<=W;i++) {
			scanf("%d%d%d",&edge[M+i].s,&edge[M+i].e,&edge[M+i].t);
			edge[M+i].t*=-1;
		}
		dp[1]=0;
		for(i=1;i<=N;i++) {
			for(j=1;j<=M*2+W;j++) {
				dp[edge[j].e] = min(dp[edge[j].e],dp[edge[j].s]+edge[j].t);
			}
		}
		bool t=false;
		for(i=1;i<=N;i++) {
			for(j=1;j<=M*2+W;j++) {
				if(dp[edge[j].e] >= dp[edge[j].s]+edge[j].t) {
					printf("YES\n");
					t=true;
					break;
				}
			}
			if(t) break;
		}
		if(!t) printf("NO\n");
	}
}