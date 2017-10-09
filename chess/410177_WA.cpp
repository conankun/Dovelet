#include<iostream>
using namespace std;
int n;
struct A {
	int black,white;
};
A chess[10000];
int dp[16][16];
int main() {
	int i,j,k;
	for(;scanf("%d%d",&chess[++n].black,&chess[n].white)!=-1;);
	for(i=1;i<=n;i++) {
		int m = min(15,i);
		for(j=m;j>=0;j--) {
			for(k=m;k>=0;k--) {
				if(dp[j][k] < dp[j-1][k]+chess[i].black && j > 0) dp[j][k] = dp[j-1][k]+chess[i].black;
				if(dp[j][k] < dp[j][k-1]+chess[i].white && k > 0) dp[j][k] = dp[j][k-1]+chess[i].white;
			}
		}
	}
	printf("%d",dp[15][15]);
}