#include <iostream> 
using namespace std; 
int arr[1001][1001]={0,}; 
int dp[1001][1001]={0,}; 
int main() { 
    int n; 
    cin>>n; 
    for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) cin>>arr[i][j]; 
      
    dp[1][1] = arr[1][1]; 
    for(int i=2;i<=n;i++) { 
        for(int j=1;j<=i;j++) { 
            dp[i][j] = max(dp[i-1][j-1]+arr[i][j],dp[i-1][j]+arr[i][j]); 
        } 
    } 
  
    int max=0; 
    for(int i=1;i<=n;i++) if(dp[n][i] > max) max = dp[n][i]; 
    cout<<max; 
  
} 
 
