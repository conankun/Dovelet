#include<iostream>
using namespace std;
int dp[1000];
int n;
int main() {
	int i,j;
	cin>>n;
	for(i=0;i<n;i++) {
		int a,b;
		cin>>a>>b;
		a = a/2+a%2;
		b = b/2 + b%2;
		if(b > a) {
			int temp = a;
			a = b;
			b = temp;
		}
		for(j=a;j<=b;j++) dp[j]++;
	}
	int ans=0;
	for(i=1;i<=999;i++) {
		if(dp[i] > ans) ans = dp[i];
	}
	cout<<ans*10;
}