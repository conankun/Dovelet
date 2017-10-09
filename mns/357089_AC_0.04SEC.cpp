#include<iostream> 
using namespace std; 
int mns[100]={0}; 
int dp[100]={1}; 
int n; 
int mxs=0; 
int main() { 
    cin>>n; 
    for(int i=0;i<n;i++) cin>>mns[i]; 
  
    for(int i=1;i<n;i++) { 
        int mx=0; 
        for(int j=i-1;j>=0;j--) { 
            if(dp[j] > mx && mns[j] < mns[i]) { 
                mx = dp[j]; 
            } 
        } 
        dp[i] = mx+1; 
        if(mx+1 > mxs) mxs=mx+1; 
    } 
    cout<<mxs; 
} 
 
