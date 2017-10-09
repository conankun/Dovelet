#include<iostream> 
#include<algorithm> 
using namespace std; 
int n; 
struct A { 
    int s,e;  
}; 
struct B { 
    int height,value; 
}; 
bool cmp(A a,A b) { 
    if(a.s == b.s) return a.e < b.e; 
    return a.s < b.s; 
} 
A arr[100]={0}; 
B dp[100]={0}; 
int tdp[100]={0}; 
int main() { 
    cin>>n; 
    for(int i=1;i<=n;i++) { 
        cin>>arr[i].s>>arr[i].e; 
        if(arr[i].s > arr[i].e) { 
            int temp = arr[i].s; 
            arr[i].s = arr[i].e; 
            arr[i].e = temp; 
        } 
    } 
    sort(arr,arr+n+1,cmp); 
    int t=0; 
    dp[0].value=1; 
    for(int i=1;i<=n;i++) { 
        int mx=0; 
        int dpt[101]={0}; 
        for(int j=i-1;j>=0;j--) { 
            if(arr[j].e <= arr[i].s) { 
                dpt[dp[j].height+1]+=dp[j].value; 
                if(mx < dp[j].height) mx=dp[j].height; 
            } 
        } 
        dp[i].height=mx+1; 
        dp[i].value = dpt[mx+1]; 
        tdp[dp[i].height]+=dp[i].value; 
        if(dp[i].height > dp[t].height) t = i; 
    } 
    cout<<n-dp[t].height<<" "<<tdp[dp[t].height]; 
} 
 
