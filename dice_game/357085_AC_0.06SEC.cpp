#include<iostream> 
using namespace std; 
int n; 
int arr[1000]={0}; 
int c[1000]={0}; 
int dp[1000][3]={0}; 
bool tt=false; 
int main() { 
    cin>>n; 
    for(int i=0;i<n;i++) cin>>arr[i]; 
    dp[0][1]=arr[0]; 
    dp[1][0]=dp[0][1]-arr[1]; 
    if(dp[1][0] < 0) dp[1][0]=0; 
    dp[1][1]=dp[0][1]+arr[1]; //한번 전진 
    dp[1][2]=arr[0]+arr[1]; //두번 전진. 
    for(int i=2;i<n;i++) { 
        dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]))-arr[i]; 
        if(dp[i][0] < 0) dp[i][0] = 0; 
        dp[i][1]=dp[i-1][0]+arr[i]; 
        dp[i][2] = dp[i-2][0]+arr[i-1]+arr[i]; 
    } 
    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<endl; 
      
    int t=n-1; 
    for(;;) { 
        if(dp[t][0] > dp[t][1] && dp[t][0] > dp[t][2]) { 
            c[t]=1; 
            t=t-1; 
        } else if(dp[t][2] >= dp[t][0] && dp[t][2] >= dp[t][1]) { 
            c[t-2]=1; 
            t=t-3; 
        } else if(dp[t][1] >= dp[t][0] && dp[t][1] >= dp[t][2]) { 
            c[t-1]=1; 
            t=t-2; 
        } 
        if(t<=0) break; 
    } 
      
    for(int i=0;i<n;i++) { 
        if(c[i] == 1) cout<<"-"; 
        else cout<<"+"; 
    } 
} 
 
