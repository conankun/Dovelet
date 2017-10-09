#include<iostream>
using namespace std;
int dp[2000][2000];
int map[2000][2000];
int n;
int t,i,j;
int main() {
	cin>>n>>t;
	for(i=0;i<t;i++) {
		int a,b;
		cin>>a>>b;
		map[a][b]=1;
	}
	int mx=0;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
			dp[i][j]++;
			if(map[i][j] == 1) dp[i][j]=0;
			if(dp[i][j] > mx) mx = dp[i][j];
		}
	}
	cout<<mx;
}