#include<iostream>
#include<string>
using namespace std;
char s[5001];
char s2[5001];
int dp[5001][5001];
int n;
int main() {
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>s[i];
	int cc=1;
	for(i=n;i>=1;i--) s2[cc++]=s[i];
	int mx=0;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			if(s[i] == s2[j]) {
				dp[i][j] = dp[i-1][j-1]+1;
			} else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
			mx = max(dp[i][j],mx);
		}
	}
	cout<<n-mx;
}