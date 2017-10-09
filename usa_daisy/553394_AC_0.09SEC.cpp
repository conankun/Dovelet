#include<stdio.h>
int map[1000][1000],vis[1000];
int N,M,Q[100000],h=1,t;
int main() {
	scanf("%d%d",&N,&M);
	int i,j;
	for(i=1;i<=M;i++) {
		int c1,c2;
		scanf("%d%d",&c1,&c2);
		map[c1][c2]=1;
		map[c2][c1]=1;
	}
	Q[++t]=1;
	vis[1]=1;
	while(h<=t) {
		for(i=1;i<=N;i++) {
			if(vis[i]==0&&map[Q[h]][i]==1) {
				Q[++t]=i;
				vis[i]=1;
			}
		}
		h++;
	}
	bool tr=false;
	for(i=1;i<=N;i++) {
		if(vis[i]==0) {
			tr=true;
			printf("%d\n",i);
		}
	}
	if(!tr) printf("0");
}