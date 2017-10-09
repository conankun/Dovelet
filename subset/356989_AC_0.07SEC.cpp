#include<iostream>  
using namespace std;  
long long dp[10000]={0,};  
int main() {  
    long long n;  
    cin>>n;  
        
    dp[0]=1;  
    for(long long i=1;i<=n;i++) {  
        for(long long j=10000;j>=0;j--) {  
            if(j-i < 0) break;  
            if(dp[j-i] != 0) {  
                dp[j]+=dp[j-i];  
            }  
        }  
    }  
    long long s=0;  
    for(long long i=1;i<=n;i++) s+=i;  
    printf("%llu",(s%2 == 0 ? dp[s/2]/2 : 0));  
} 
 
