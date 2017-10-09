#include<iostream> 
using namespace std; 
int main() { 
    int n; 
    int arr[1000]; 
    int dp[1000]={0}; 
    int mx=0; 
    cin>>n; 
    for(int i=1;i<=n;i++) cin>>arr[i]; 
    dp[1] = arr[1]; 
    for(int i=2;i<=n;i++) { 
        dp[i]=max(dp[i-2],arr[i-1]+dp[i-3])+arr[i]; 
        if(dp[i] > mx) mx = dp[i]; 
        dp[i]=mx; 
    } 
    cout<<dp[n]; 
} 
 
