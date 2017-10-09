#include<iostream> 
using namespace std; 
int arr[10]={0}; 
int dp[200001]={0}; 
int n,sum=0; 
int main() { 
    cin>>n; 
    for(int i=0;i<n;i++) { 
        cin>>arr[i]; 
        sum+=arr[i]; 
    } 
    dp[0]=1; 
    for(int i=0;i<=100000;i++) { 
        for(int j=0;j<n;j++) { 
            if(dp[i] != 0) { 
                dp[i+arr[j]] = 1; 
            } 
        } 
    } 
    bool t=false; 
    for(int i=70000;i<=100000;i++) { 
        if(dp[i] == 0) { 
            t=true; 
            break; 
        } 
    } 
    dp[0]=0; 
    if(t) { 
        cout<<0; 
    } 
    for(int i=70000;i>=0;i--) { 
        if(dp[i] == 0 && !t) { 
            cout<<i; 
            break; 
        } 
    } 
} 
 
