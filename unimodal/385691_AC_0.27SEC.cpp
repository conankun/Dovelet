#include<iostream>
using namespace std;
long long dp[1000];
long long dp2[1000][1000]; //i까지를 이용해 j까지 만드는 경우 수.
int n;
int main() {
	cin>>n;
	int i,j,k;
	dp[1]=1;
	for(j=1;j<=n;j++) {
		dp2[j][0]=1;
		for(k=1;k<=j;k++) {
			for(i=0;i<=n;i++) {
				if(dp2[j][i] != 0) dp2[j][i+k]+=dp2[j][i];
			}
		}
	}
	dp[n]+=1;
	for(j=n-2;j>=1;j-=2) {
		dp[n]+=dp2[j][(n-j)/2];
	}
	if(n%2 == 0) dp[n]+=dp2[n/2][n/2];
	cout<<dp[n];
}