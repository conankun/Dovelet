#include<iostream>
using namespace std;
int n;
int C[1000][1000];
int dp[1000];
int main() {
	int i,j,k;
	cin>>n;
	C[0][0]=1;
	for(i=1;i<=n;i++) {
		C[i][0]=1;
		C[i][i]=1;
		for(j=1;j<i;j++) {
			C[i][j] = C[i-1][j]+C[i-1][j-1];
		}
	}
	int sum=0;
	dp[0]=1;
	dp[1]=1;
	dp[2]=1;
	for(k=3;k<=n;k++) {
		for(i=1;i<=k-1;i++) {
			j = k-i-1;
			int z=1;
			int ind=0;
			for(;z<i;z*=2,ind++);
			if((i > j || (i==j&&i==z*2-1)) && i-j <= ind) {
				dp[k]+=dp[i]*dp[j]*C[k-1][i]*C[k-i-1][j];
			}
		}
	}
	if(n == 1 || n == 2) cout<<1;
	else cout<<dp[n];
}