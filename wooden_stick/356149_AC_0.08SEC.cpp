#include<iostream> 
#include<algorithm> 
using namespace std; 
struct A { 
    int l,w; 
}; 
bool cmp(A a,A b) { 
    if(a.l == b.l) return a.w < b.w; 
    return a.l < b.l; 
} 
int n; 
A arr[5000]={0}; 
int dp[5000]={0}; 
int main() { 
    cin>>n; 
    for(int i=0;i<n;i++) cin>>arr[i].l>>arr[i].w; 
    sort(arr,arr+n,cmp); 
    int t=0; 
    for(int i=0;i<n;i++) { 
        int mx=0; 
        for(int j=i-1;j>=0;j--) { 
            if(dp[j] > mx && (arr[j].l > arr[i].l || arr[j].w > arr[i].w)) mx = dp[j]; 
        } 
        dp[i]=mx+1; 
        if(t < dp[i]) t = dp[i]; 
    } 
    cout<<t; 
}