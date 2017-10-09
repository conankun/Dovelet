#include<iostream>
using namespace std;
int n,k;
int dp[1000][1000];
int map[1000][1000];
int min(int a,int b) {
	if(a < b) return a;
	return b;
}
int main() {
	int i,j,z;
	cin>>n>>k;
	for(i=1;i<=n-1;i++) {
		for(j=i+1;j<=n;j++) {
			cin>>map[i][j];
			if(i == 1) dp[i][j] = map[i][j];
		}
	}
	for(i=2;i<=k;i++) {
		for(j=i;j<=n;j++) {
			for(z=j-1;z>=i-1;z--) {
				if(dp[i-1][z]+map[z][j] > dp[i][j])  {
					dp[i][j] = dp[i-1][z]+map[z][j];
				}
			}
		}
	}
	int mx=0;
	for(i=k;i<=n;i++) {
		if(mx < dp[k][i]) {
			mx = dp[k][i];
		}
	}
	cout<<mx;
}