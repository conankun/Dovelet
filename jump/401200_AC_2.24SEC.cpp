#include<stdio.h>
#include<stdlib.h>
struct A {
int x,jump,spring;
};
int dp[501][501];
A spring[501];
int n;
int main() {
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;i++) {
		scanf("%d%d%d",&spring[i].x,&spring[i].jump,&spring[i].spring);
	}
	dp[1][1]=1;
	if(spring[2].x-spring[1].x <= spring[2].jump && spring[2].spring == 1) {
		dp[1][2]=1;
	}
	if(spring[2].x-spring[1].x <= spring[1].jump) {
		dp[2][1]=1;
	}
	for(k=3;k<=n;k++) {
		for(i=1;i<=k-1;i++) {
			for(j=1;j<=k-1;j++) {
				if(i == j && i != 1) continue;
				if(spring[k].x-spring[i].x <= spring[i].jump) {
					dp[k][j]+=dp[i][j];
					dp[k][j]%=1000;
				}
				if(spring[k].x-spring[j].x <= spring[k].jump && spring[k].spring != 0) {
					dp[i][k]+=dp[i][j]; 
					dp[i][k]%=1000;
				}
			}
		}
	}
	int sum=0;
	for(i=1;i<=n;i++) {
		if(spring[n].x-spring[i].x <= spring[n].jump) {
			sum+=dp[n][i];
			sum%=1000;
		}
	}
	printf("%d",sum);
}