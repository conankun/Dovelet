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
	int left=1;
	int right=0;
	for(k=3;k<=n;k++) {
		int z=1;
		for(;z<k;z*=2);
		if(z != k) {
			z/=2;
		}
		if(z+z/2 <= k) right++;
		else left++;
		dp[k]=dp[left]*dp[right]*C[k-1][left]*C[k-left-1][right];
	}
	if(n == 1 || n == 2) cout<<1;
	else cout<<dp[n];
}