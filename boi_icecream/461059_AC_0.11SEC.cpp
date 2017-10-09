#include<stdio.h>
int nots[300][300];
int N,M;
int main() {
	scanf("%d%d",&N,&M);
	int i,j,k;
	for(i=1;i<=M;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		nots[a][b]=1;
		nots[b][a]=1;
	}
	int ans=0;
	for(i=1;i<=N;i++) {
		for(j=i+1;j<=N;j++) {
			if(nots[i][j]) continue;
			for(k=j+1;k<=N;k++) {
				if(nots[i][k] || nots[j][k]) continue;
				ans++;
			}
		}
	}
	printf("%d",ans);
}