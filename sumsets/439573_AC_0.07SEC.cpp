#include<iostream>  
#include<fstream>  
#include<cmath>  
using namespace std;  
int dp[1000011];  
int n;
int cnt=0; 
int main() {  
    cin>>n;
dp[1]=1;
    dp[2]=1;  
    dp[3]=2;  
    for(int i=4;i<=n;i++) {  
        if(i%2 == 0) dp[i] = dp[i-1]+dp[i/2];  
        else {  
            for(int j=2;j<=i-1;j*=2) {  
                if(i-1 == j) {  
                    dp[i]++;  
                    break;  
                }  
            }  
            dp[i] += dp[i-1];  
        }  
        dp[i]%=1000000000;  
    }  
    cout<<dp[n];  
}