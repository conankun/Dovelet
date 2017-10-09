#include<iostream> 
using namespace std; 
int arr[100000]; 
int dp[100000]={0}; 
int v[100000]={0}; 
int main() { 
    int n; 
    cin>>n; 
    for(int i=0;i<n;i++) cin>>arr[i]; 
    int sum=0; 
    for(int i=0;i<n;i++) { 
        sum+=arr[i]; 
        dp[i] = sum%n; 
        v[dp[i]]++; 
        if(dp[i] == 0) { 
            cout<<i+1<<endl; 
            for(int j=0;j<=i;j++) cout<<arr[j]<<endl; 
            break; 
        } else if(v[dp[i]] >= 2) { 
            int j; 
            for(j=i-1;j>=0;j--) if(dp[i] == dp[j]) break; 
            cout<<i-j<<endl; 
            for(int k=j+1;k<=i;k++) cout<<arr[k]<<endl; 
            break; 
        } 
    } 
} 
 
