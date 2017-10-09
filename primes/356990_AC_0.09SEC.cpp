#include<iostream> 
using namespace std; 
int primes[10000]={2,0}; 
int dp[10001]={1,0}; 
int dpl[10001]={0}; 
int pi=1; 
int main() { 
    int n; 
      
    //1부터 n까지의 소수를 구한다. 
    for(int i=3;i<=10000;i+=2) { 
        bool b=true; 
        for(int j=2;j*j<=i;j++) { 
            if(i%j==0)  { 
                b=false; 
                break; 
            } 
        } 
        if(b) { 
            primes[pi]=i; 
            pi++; 
        } 
    } 
    //부분합을 미리 구해놓는다.O(n^2) 
    dp[2]=1; 
    dpl[2]=2; 
    for(int i=1;i<pi;i++) { 
        for(int j=10000;j>=1;j--) { 
            if(dp[j] > 0 && dpl[j]==primes[i-1] && primes[i]+j <= 10000) { 
                dp[j+primes[i]] += 1; 
                dpl[j+primes[i]] = primes[i]; 
            } 
        } 
        dp[primes[i]]+=1; 
        dpl[primes[i]]=max(primes[i],dpl[primes[i]]); 
    } 
    while(cin>>n) { 
        if(n == 0) break; 
        cout<<dp[n]<<endl; 
    } 
} 
 
