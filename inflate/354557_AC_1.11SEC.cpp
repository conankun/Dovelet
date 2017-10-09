 #include<iostream> 
#include<algorithm> 
using namespace std; 
struct A { 
    int score,time; 
}; 
A arr[10000]; 
int dp[10001]={0}; 
bool cmp(A a,A b) { 
    return a.time < b.time; 
} 
int main() { 
    int m,n; 
    int min=999999999; 
    cin>>m>>n; 
    for(int i=0;i<n;i++) { 
        cin>>arr[i].score>>arr[i].time; 
        if(arr[i].score < min) min = arr[i].score; 
    } 
    sort(arr,arr+n,cmp); 
    dp[0]=1; 
    int mx=0; 
    for(int i=0;i<=m;i++) { 
        for(int j=0;j<n;j++) { 
            if(dp[i] != 0 && i+arr[j].time <= m) { 
                dp[i+arr[j].time] = max(dp[i+arr[j].time],dp[i]+arr[j].score); 
                if(dp[i+arr[j].time] > mx) mx = dp[i+arr[j].time]; 
            } 
        } 
    } 
    cout<<mx-1; 
} 
 
