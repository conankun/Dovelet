#include<iostream>
using namespace std;
int n,q;
int dp[2000000];
int main() {
	cin>>n>>q;
	int i,j;
	int c=0;
	for(i=1;i<=n;i++) {
		int a;
		cin>>a;
		for(j=c;j<=c+a-1;j++) dp[j]=i;
		c=c+a;
	}
	for(i=1;i<=q;i++) {
		int a;
		cin>>a;
		cout<<dp[a]<<endl;
	}
}