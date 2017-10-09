 #include<iostream> 
#include<fstream> 
#include<cmath> 
using namespace std; 
int dp[1000001]={0}; 
int n; 
int vis[1000]={0}; 
int cnt=0; 
fstream in("sumsets.in"); 
ofstream out("sumsets.out"); 
int main() { 
    cin>>n; 
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
 
