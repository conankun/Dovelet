#include<iostream>
using namespace std;
int n;
unsigned long long dp[1000][1000];
int main() {
	cin>>n;
	int i,j,k;
	for(i=0;i<=9;i++) dp[1][i]=1;
	for(i=2;i<=n/2;i++) {
	for(j=0;j<=101;j++) {
		if(dp[i-1][j] != 0)
			for(k=0;k<=9;k++) {
				dp[i][j+k]+=dp[i-1][j];
			}
		}
	}
	unsigned long long sum=0;
	for(i=0;i<=45;i++) sum+=(dp[n/2][i]*dp[n/2][i]);
	cout<<sum;
}