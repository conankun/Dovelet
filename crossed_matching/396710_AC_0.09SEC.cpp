#include<iostream>
#include<algorithm>
using namespace std;
int a[10000];
int b[10000];
int n,m;
int dp[200][200];
int main() {
	cin>>n>>m;
	int i,j,k,l;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>b[i];
	int ans=0;
	for(i=1;i<=n;i++) { //a
		for(j=1;j<=m;j++) {//b
			dp[i][j] = max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
			for(l=1;l<i;l++) {	
				for(k=1;k<j;k++) {
					int g = (a[l] == b[j] && a[i] == b[k] && a[l] != a[i]);
					if(dp[l-1][k-1]+g*2 > dp[i][j]) {
						dp[i][j] = dp[l-1][k-1]+g*2;
					}
				}
			}
			if(dp[i][j] > ans) {
				ans = dp[i][j];
			}
		}
	}
	cout<<ans;
}