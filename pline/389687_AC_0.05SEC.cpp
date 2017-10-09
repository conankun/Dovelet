#include<iostream>
using namespace std;
int m,n;
int words[100000];
int hap[100000];
int dp[101][10001];
int main() {
	cin>>m>>n;
	int i,j,k;
	for(i=1;i<=n;i++) cin>>words[i];
	for(i=1;i<=n;i++) hap[i]=hap[i-1]+words[i]+1;
	int ind;
	for(i=1;i<=n;i++) {
		for(j=i;j<=n;j++) {
			int mn = 99999999;
			for(k=j-1;k>=i-1;k--) {
				//m-(k+1 ~ j)
				//m-(hap[j]-hap[k]-1)
				if(dp[i-1][k]+(m-(hap[j]-hap[k]-1))*(m-(hap[j]-hap[k]-1))<mn && hap[j]-hap[k]-1 <= m) {
					mn = dp[i-1][k]+(m-(hap[j]-hap[k]-1))*(m-(hap[j]-hap[k]-1));
				}
			}
			if(i == 1) {
				if(hap[j]-hap[0]-1 <= m)
				mn = (m-(hap[j]-hap[0]-1))*(m-(hap[j]-hap[0]-1));
				else
				mn = 99999999;
			}
			dp[i][j] = mn;
		}
		if(dp[i][n] < 99999999) {
			ind = i;
			break;
		}
		ind =i;
	}
	cout<<dp[ind][n];
}