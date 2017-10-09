#include<iostream>
using namespace std;
int n;
int p[1000];
int dp[100000];
int i,j,sum;
int main() {
	cin>>n;
for(i=0;i<n;i++) {
		cin>>p[i];
		sum+=p[i];
	}
	dp[0]=1;
for(i=0;i<n;i++) {
	for(j=sum;j>=0;j--) {
		if(dp[j] != 0) dp[j+p[i]]+=dp[j];
		}
	}
if(sum%2 == 1) cout<<"impossible";
else
cout<<dp[sum/2];
}