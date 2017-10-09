#include<iostream>
using namespace std;
int n;
struct A {
	int black,white;
};
A chess[10000];
int dp[16][16];
int min(int a,int b) {
	if(a < b) return a;
	return b;
}
int main() {
	int i,j,k;
	for(i=1;;i++) {
		if(scanf("%d%d",&chess[i].black,&chess[i].white) == -1) break;
		n++;	
	}
	for(i=1;i<=n;i++) {
		int m = min(15,i);
		for(j=m;j>=0;j--) {
			for(k=m;k>=0;k--) {
				if(j > 0) if(dp[j][k] < dp[j-1][k]+chess[i].black) dp[j][k] = dp[j-1][k]+chess[i].black;
				if(k > 0) if(dp[j][k] < dp[j][k-1]+chess[i].white) dp[j][k] = dp[j][k-1]+chess[i].white;
			}
		}
	}
	printf("%d",dp[15][15]);
}