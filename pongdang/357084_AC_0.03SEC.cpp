#include<iostream> 
using namespace std; 
int arr[10000]; 
int dp[10001]={0}; 
int n; 
int main() { 
    cin>>n; 
    for(int i=0;i<n;i++) cin>>arr[i]; 
    dp[0]=arr[0]; 
    dp[1]=arr[1]; 
    dp[2]=arr[2]; 
    for(int i=3;i<n+1;i++) { 
        dp[i]=min(dp[i-1],min(dp[i-2],dp[i-3]))+arr[i]; 
    } 
    cout<<dp[n]; 
} 
 
