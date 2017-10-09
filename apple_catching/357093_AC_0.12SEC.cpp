#include<iostream> 
using namespace std; 
int arr[10000]={1,0}; 
int dp[10000][100]={0}; 
int main() { 
    int t,w; 
    cin>>t>>w; 
    for(int i=1;i<=t;i++) cin>>arr[i]; 
  
    //dp[0][0] = 1; 
    for(int i=1;i<=t;i++) { 
        for(int k=i-1;k>=0;k--) { 
            for(int j=0;j<=w;j++) { 
                int c = (arr[i] == arr[k] ? 1 : 0); 
                int d = (arr[i] != arr[k] ? 1 : 0); 
                if(arr[k] == arr[i]) { 
                    dp[i][j] = max(dp[i][j],dp[k][j]+c); 
                } 
                if(arr[k] != arr[i]) { 
                    if(j >= 1) dp[i][j] = max(dp[i][j],dp[k][j-1]+d); 
                } 
            } 
        } 
    } 
    int mx=0; 
    for(int i=0;i<=w;i++) { 
        if(dp[t][i] > mx) mx = dp[t][i]; 
    } 
    cout<<mx; 
} 
 
