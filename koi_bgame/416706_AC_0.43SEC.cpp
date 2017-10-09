#include<stdio.h>
#include<queue>
struct A {
	int e;
	char value;
};
int dp[1001][501];
int chk[1001][501];
int n,m,K;
char board[1001];
A map[501][1001];
int mapindex[501];
int main() {
	int i,j,k;
	scanf("%d\n",&n);
	for(i=1;i<=n;i++) scanf("%c\n",&board[i]);
	scanf("%d%d",&m,&K);
	for(i=1;i<=K;i++) {
		int a,b;
		char c;
		scanf("%d%d\n%c",&a,&b,&c);
		A cc;
		cc.e = b;
		cc.value = c;
		map[a][++mapindex[a]]=cc;
		cc.e = a;
		map[b][++mapindex[b]]=cc;
	}
	chk[0][1]=1;
	int ans=0;
	for(i=0;i<=n;i++) {
		for(j=1;j<=m;j++) {
			if(chk[i][j]==1) {
				for(k=1;k<=mapindex[j];k++) {
					if(dp[i+1][map[j][k].e] <= dp[i][j]+(board[i+1]==map[j][k].value)*10) {
						dp[i+1][map[j][k].e] = dp[i][j]+(board[i+1]==map[j][k].value)*10;
						chk[i+1][map[j][k].e]=1;
						if(dp[i+1][map[j][k].e] > ans) ans = dp[i+1][map[j][k].e];
					}
				}
			}
		}
	}
	printf("%d",ans);
}
