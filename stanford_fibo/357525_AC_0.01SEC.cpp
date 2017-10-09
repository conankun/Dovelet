#include<iostream> 
using namespace std; 
int dp[100000]={0,1}; 
int main() { 
    int n; 
    for(int i=2;i<=15000;i++) { 
        dp[i] = dp[i-1]+dp[i-2]; 
        dp[i]%=10000; 
    } 
    while(cin>>n) { 
        if(n == -1) break; 
        else { 
            //주기 15000 
            cout<<dp[n%15000]<<endl; 
        } 
    } 
} 
 
