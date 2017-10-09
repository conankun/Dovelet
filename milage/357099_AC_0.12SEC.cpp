#include<iostream> 
using namespace std; 
int dp[200][200]={0}; 
int map[200][200]={0}; 
int n,k; 
int main() { 
    cin>>n>>k; 
    for(int i=1;i<=n-1;i++) { 
        for(int j=1;j<=n-i;j++) { 
            cin>>map[i][i+j]; 
            if(i == 1) dp[1][i+j] = map[i][i+j]; 
        } 
    } 
    for(int i=2;i<=k;i++) { 
        for(int j=i+1;j<=n;j++) { 
            int mx=0; 
            for(int k=j-1;k>=1;k--) { 
                if(dp[i-1][k] == 0) break; 
                if(dp[i-1][k]+map[k][j] > mx) mx = dp[i-1][k]+map[k][j]; 
            } 
            dp[i][j]=mx; 
        } 
    } 
  
    int mx=0; 
    for(int i=1;i<=n;i++) { 
        if(dp[k][i] > mx) mx = dp[k][i]; 
    } 
    cout<<mx; 
} 
 
