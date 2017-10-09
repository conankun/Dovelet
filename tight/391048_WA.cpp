#include<iostream>
using namespace std;
long long k,n;
long long dp[1000][1000];
long long sum[1000][1000];
int main() {
	cin>>k>>n;
	long long i,j,z;
	for(i=0;i<=k;i++) dp[1][i] = 1;
	for(i=2;i<=n;i++) {
		for(j=0;j<=k;j++) {
			if(j-1 >= 0) dp[i][j]+=dp[i-1][j-1];
			if(j+1 <= k) dp[i][j]+=dp[i-1][j+1];
			dp[i][j]+=dp[i-1][j];
		}
	}
	for(i=0;i<=k;i++) sum[1][i] = 1;
	for(i=2;i<=n;i++) {
		for(j=0;j<=k;j++) {
			for(z=0;z<=k;z++) sum[i][j]+=sum[i-1][z];
		}
	}
	long long sum1=0;
	long long sum2=0;
	for(i=0;i<=k;i++) sum1+=dp[n][i];
	for(i=0;i<=k;i++) sum2+=sum[n][i];
	printf("%.5lf",(sum1/(double)sum2)*100);
}