#include<iostream>
using namespace std;
int dp1[1000001];
int dp2[1000001];
int a[1000000];
int b[1000000];
int t;
int n,m;
int d1[1000001];
int d2[1000001];
int main() {
	int i,j;
	cin>>t;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(i=1;i<=m;i++) cin>>b[i];
	for(i=1;i<=n;i++) dp1[i] = dp1[i-1]+a[i];
	for(i=1;i<=m;i++) dp2[i] = dp2[i-1]+b[i];
	for(i=1;i<=n;i++) {
		for(j=1;j<=i;j++) {
			d1[dp1[i]-dp1[j-1]]+=1;
		}
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=i;j++) {
			d2[dp2[i]-dp2[j-1]]+=1;
		}
	}
	int sum=0;
	for(i=1;i<=t-1;i++) {
		sum+=d1[i]*d2[t-i];
	}
	cout<<sum;
}