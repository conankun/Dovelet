#include<stdio.h>
int gold[1000],silver[1000],dp[111][5011],N,Mg,Ms;
int main() {
	scanf("%d%d%d",&N,&Ms,&Mg);
	int i,j,k;
	for(i=1;i<=N;i++) {
		scanf("%d%d",&silver[i],&gold[i]);
	}
	for(i=0;i<=N;i++) for(j=0;j<=Mg;j++) dp[i][j]=999999999;
	int ans=0,mx=0;
	dp[0][0]=0;
	for(i=1;i<=N;i++) {
		for(j=ans;j>=0;j--) {
			for(k=mx;k>=0;k--) {
				if(k+gold[i]<=Mg) {
					if(dp[j][k]+silver[i]<=Ms) {
						if(dp[j+1][k+gold[i]] > dp[j][k]+silver[i]) {
							dp[j+1][k+gold[i]]=dp[j][k]+silver[i];
						}
						if(k+gold[i] > mx) mx = k+gold[i];
						if(j+1 > ans) ans = j+1;
					}
				}
			}
		}
	}
	printf("%d",ans);
}