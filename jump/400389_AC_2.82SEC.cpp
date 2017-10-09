#include<iostream>
#include<stdlib.h>
using namespace std;
struct A {
	int x,jump,spring;
};
int dp[1000][1000];
A spring[1000];
int n;
int main() {
	scanf("%d",&n);
	int i,j,k;
	for(i=1;i<=n;i++) {
		scanf("%d%d%d",&spring[i].x,&spring[i].jump,&spring[i].spring);
	}
	dp[1][1]=1;
	for(i=2;i<=2;i++) {
		if(abs(spring[i].x-spring[1].x) <= spring[i].jump && spring[i].spring == 1) {
			dp[1][i]=1;
		}
		if(abs(spring[i].x-spring[1].x) <= spring[1].jump) {
			dp[i][1]=1;
		}
	}
	for(k=3;k<=n;k++) {
		for(i=1;i<=k-1;i++) {
			for(j=1;j<=k-1;j++) {
				if(i == j && i != 1) continue;
				if(abs(spring[i].x-spring[k].x) <= spring[i].jump) {
					dp[k][j]+=dp[i][j];
					dp[k][j]%=1000;
				}
				if(abs(spring[k].x-spring[j].x) <= spring[k].jump && spring[k].spring != 0) {
					dp[i][k]+=dp[i][j]; 
					dp[i][k]%=1000;
				}
			}
		}
	}

	int sum=0;
	for(i=1;i<=n;i++) {
		if(abs(spring[i].x-spring[n].x) <= spring[n].jump) {
			sum+=dp[n][i];
			sum%=1000;
		}
	}
	printf("%d",sum);
}