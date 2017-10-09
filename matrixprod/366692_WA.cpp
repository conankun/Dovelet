#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct A {
	int a,b;
};
A arr[1000];
int dp[1000][1000];
int points[1000];
int min(int a,int b) {
	if(a < b) return a;
	return b;
}
int main() {
	cin>>n;
	int i,j,k;
	for(i=0;i<=n;i++) {
		cin>>points[i];
	}
	int c=1;
	for(i=0;i<n;i++) {
		arr[c].a = points[i];
		arr[c].b = points[i+1];
		c++;
	}
	for(i=0;i<=999;i++) fill(dp[i],dp[i]+1000,999999999);
	for(i=1;i<=n;i++) dp[i][i]=0;
	for(j=1;j<=n;j++) {
		dp[j][j]=0;
		for(i=1;i<=n-j+1;i++) { //i = i, j=i+j-1
			for(k=i;k<i+j-1;k++) {
				dp[i][i+j-1]=min(dp[i][i+j-1],dp[i][k]+dp[k+1][j]+(arr[i].a*arr[k].b*arr[j].b));
			}
		}
	}
	cout<<dp[1][n];
}