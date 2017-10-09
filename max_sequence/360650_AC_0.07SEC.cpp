#include<iostream>
using namespace std;
int n,i,j;
int data[10000];
int main() {
	cin>>n;
	for(i=1;i<=n;i++) cin>>data[i];
	int mx=-999999;
	for(i=1;i<=n-1;i++) {
		int dp1[1001]={0};
		int dp2[1001]={0};
		dp1[1] = data[1];
		for(j=2;j<=n;j++) {
			dp1[j] = max(dp1[j-1]+data[j],data[j]);
		}
		int mx2=data[i+1];
		dp2[i+1] = data[i+1];
		for(j=i+2;j<=n;j++) {
			dp2[j] = max(dp2[j-1]+data[j],data[j]);
			if(dp2[j] > mx2) mx2 = dp2[j];
		}
		if(dp1[i]+mx2 > mx) mx = dp1[i]+mx2;
	}
	cout<<mx;
}