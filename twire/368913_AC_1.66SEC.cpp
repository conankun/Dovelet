#include<iostream>
#include<stdlib.h>
using namespace std;
int n,c;
int arr[1000000];
int dp[100001][101];
int main() {
	cin>>n>>c;
	int i,j,k;
	int high=0,low=9999999;
	for(i=1;i<=n;i++) {
		scanf("%d",&arr[i]);
		if(high < arr[i]) high = arr[i];
		if(low > arr[i]) low = arr[i];
	}
	for(i=1;i<=n;i++) {
		for(j=arr[i];j<=high;j++) {
			int g = (j-arr[i])*(j-arr[i]);
			int mn=2147483647;
			for(k=arr[i-1];k<=high;k++) {
				if(dp[i-1][k]+abs(j-k)*c < mn) mn = dp[i-1][k]+abs(j-k)*c;
			}
			dp[i][j]=g+mn;
		}
	}
	int min=2147483647;
	for(i=arr[n];i<=high;i++) {
		if(min > dp[n][i]) min = dp[n][i];
	}
	cout<<min;
}