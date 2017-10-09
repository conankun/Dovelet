#include<iostream>
using namespace std;
int n;
int chord[101][101];
int dp[101][101];
int max(int a,int b) {
	if(a > b) return a;
	return b;
}
int main() {
	cin>>n;
	int d,i,j,k;
	for(i=0;i<n;i++) {
		int a,b;
		cin>>a>>b;
		if(b < a) {
			int temp = a;
			a = b;
			b = temp;
		}
		chord[a][b]=1;
	}
	for(d=1;d<=100;d++) {
		for(i=1;i<=100-d+1;i++) {
			j = i+d-1;
			for(k=i;k<=j-1;k++) {
				dp[i][j]=max(dp[i][k]+dp[k+1][j]+chord[k][j],dp[i][j]);
			}
		}
	}
	cout<<dp[1][100];
}