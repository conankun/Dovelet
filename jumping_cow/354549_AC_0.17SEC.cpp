#include<iostream> 
using namespace std; 
int n,arr[150001]={0},dp[150001][2]={0}; 
int main() { 
    cin>>n; 
    for(int i=1;i<=n;i++) cin>>arr[i]; 
    int mx=0; 
    for(int i=1;i<=n;i++) { 
        dp[i][0] = max(dp[i-1][1]+arr[i],dp[i-1][0]); 
        dp[i][1] = max(dp[i-1][0]-arr[i],dp[i-1][1]); 
        if(dp[i][0] > mx) mx = dp[i][0]; 
        if(dp[i][1] > mx) mx = dp[i][1]; 
    } 
    cout<<mx; 
} 
 
