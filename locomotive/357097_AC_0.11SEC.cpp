#include <iostream> 
using namespace std; 
int n; 
int t; 
int train[50001]; 
int dp[5][50001]={0}; 
int main() { 
    cin>>n; 
    for(int i=0;i<n;i++) cin>>train[i]; 
    cin>>t; 
    dp[0][0]=train[0]; 
    for(int i=1;i<n;i++) { 
        dp[0][i]=dp[0][i-1]+train[i]; 
    } 
      
    for(int i=2;i<=4;i++) { 
        dp[i][0]=0; 
        for(int j=1;j<t;j++) { 
            dp[i][j]=dp[0][j]; 
        } 
        for(int j=t-1;j<n;j++) { 
            if(dp[0][j]-dp[0][j-t]+dp[i-1][j-t] > dp[i][j]) { 
                dp[i][j] = dp[0][j]-dp[0][j-t]+dp[i-1][j-t]; 
            } 
            dp[i][j+1] = dp[i][j]; 
        } 
    } 
    cout<<dp[4][n-1]; 
} 
 
