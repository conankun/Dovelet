#include<iostream> 
using namespace std; 
int dis[105]={0}; 
int tl; 
int sum=0; 
int n; 
int tt[101]={0}; 
int dp[101]={0}; 
int main() { 
    cin>>tl; 
    cin>>n; 
    for(int i=1;i<=n+1;i++) { 
        int s; 
        cin>>s; 
        sum+=s; 
        dis[i]=sum; 
    } 
    for(int i=1;i<=n;i++) { 
        cin>>tt[i]; 
    } 
    for(int i=1;i<=n+1;i++) { 
        int mn=9999999; 
        for(int j=i-1;j>=0;j--) { 
            if(dis[i]-dis[j] <= tl && dp[j] < mn) { 
                mn = dp[j]; 
            } 
        } 
        dp[i] = mn+tt[i]; 
    } 
    cout<<dp[n+1]; 
} 
 
