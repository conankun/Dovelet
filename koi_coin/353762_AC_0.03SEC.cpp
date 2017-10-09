#include<iostream> 
using namespace std; 
int dp[100000]={0}; 
int coin[1000]={0}; 
int coint[1000]={0}; 
int t,k; 
main() {cin>>t>>k;for(int i=0;i<k;i++) cin>>coin[i]>>coint[i];dp[0]=1;for(int i=0;i<k;i++){for(int j=t;j>=0;j--) {if(dp[j] != 0) {for(int k=1;k<=coint[i];k++)dp[j+(coin[i]*k)]+=dp[j];}}}cout<<dp[t];}