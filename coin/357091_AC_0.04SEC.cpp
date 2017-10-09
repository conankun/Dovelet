#include<iostream> 
using namespace std; 
int cc[5]={1,5,10,25,50}; 
int dp[201]={0}; 
int main() { 
    double n; 
    int coin; 
    cin>>n; 
    coin = 100 * n; 
  
    dp[0]=1; 
    for(int i=0;i<5;i++) { 
        for(int j=cc[i];j<=coin;j++) { 
            dp[j]+=dp[j-cc[i]]; 
        } 
    } 
      
    cout<<dp[coin]; 
} 
 
