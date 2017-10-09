#include<iostream>
using namespace std;
int n;
int data[1000];
int dp[1000][1000];
int bt[1000][1000];
int i,j,k;
int main() {
	cin>>n;
	for(i=1;i<=n;i++) cin>>data[i];
	for(i=2;i<=n;i++) {
		for(j=0;j<=n;j++) {
			if(i+j > n) break;
			int mx=0;
			int mn=99999999;
			for(k=j+1;k<=i+j;k++) if(data[k] > mx) mx = data[k];
			for(k=j+1;k<=i+j;k++) if(data[k] < mn) mn = data[k];
			dp[j+1][i+j] = mx-mn;
			bt[j+1][i+j] = 0;
			int r=0;
			for(k=j+2;k<i+j;k++) {
				if(dp[j+1][k]+dp[k+1][i+j] > dp[j+1][i+j] || (dp[j+1][k]+dp[k+1][i+j] == dp[j+1][i+j] && dp[j+1][k] > r)) {
					dp[j+1][i+j] = dp[j+1][k]+dp[k+1][i+j];
					r=dp[j+1][k];
					bt[j+1][i+j] = k;
				}
			}
		}
	}
	int cnt=1;
	int back[1000]={0};
	back[0]=n;
	int y=1,x=n;
	while(bt[y][x] > 0) {
		back[cnt++]=bt[y][x];
		x = bt[y][x];
	}
	cout<<dp[1][n]<<endl;
	cout<<cnt<<endl;
	for(i=cnt;i>=1;i--) {
		cout<<back[i-1]-back[i]<<" ";
	}
}