 #include<iostream> 
using namespace std; 
int main() { 
    int n; 
    int arr[301]={0,}; 
    int dp[301]={0,}; 
    cin>>n; 
    for(int i=1;i<=n;i++) cin>>arr[i]; 
  
      
    dp[1]=arr[1]; 
    dp[2]=dp[1]+arr[2]; 
    for(int i=3;i<=n;i++) { 
        if(dp[i-2] < arr[i-1]+dp[i-3]) dp[i] = arr[i-1]+dp[i-3]+arr[i]; 
        else dp[i] = dp[i-2]+arr[i]; 
    } 
    cout<<dp[n]; 
} 
 
