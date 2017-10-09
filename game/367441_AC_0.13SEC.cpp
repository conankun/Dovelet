#include<iostream>
using namespace std;
int n;
int data[1000];
int hap[1000];
int dp[1000][1000];
int sum;
int max(int a,int b) {
	if(a > b) return a;
	return b;
}
int main() {
	int i,j,d;
	cin>>n;
	for(i=1;i<=n;i++) {
		cin>>data[i];
		sum+=data[i];
	}
	for(i=1;i<=n;i++) hap[i] = hap[i-1]+data[i];
	for(d=1;d<=n;d++) {
		for(i=1;i<=n-d+1;i++) {
			j = i+d-1;
			dp[i][j]=max((hap[j-1]-hap[i-1])-dp[i][j-1]+data[j],(hap[j]-hap[i])-dp[i+1][j]+data[i]);
		}
	}
	cout<<dp[1][n]<<" "<<sum-dp[1][n];
}