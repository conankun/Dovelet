#include<iostream>
using namespace std;
int n,i,j,k;
char map[999][999];
int dp[999][999];
int main() {
	cin>>n;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) cin>>map[i][j];
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
			if(map[i][j] == '0') dp[i][j]=0;
		}
	}
	bool t=0;
	for(k=2;k<=n;k++) {
		int cnt=0;
		for(i=1;i<=n;i++) {
			for(j=1;j<=n;j++) {
				if(dp[i][j] >= k) {
					cnt++;
				}
			}
		}
		if(cnt) {
			t=1;
			cout<<k<<" "<<cnt<<endl;
		}
	}
	if(!t) cout<<0;
}