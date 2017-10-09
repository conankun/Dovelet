#include<iostream>
using namespace std;
int n;
int data[3000];
int dp[3000][3000];
int hap[3000];
int max(int a,int b) {
	if(a > b) return a;
	return b;
}
int main() {
	int i,j,d;
	cin>>n;
	for(i=1;i<=n;i++) cin>>data[i];
	for(i=1;i<=n;i++) hap[i] = hap[i-1]+data[i];
	for(d=1;d<=n;d++) { //j
		for(i=1;i<=n-d+1;i++) { //i
			j = i+d-1;
			dp[i][j] = max(dp[i+1][j]+(hap[j]-hap[i])+data[i],dp[i][j-1]+(hap[j-1]-hap[i-1])+data[j]);
		}
	}
	cout<<dp[1][n];
}