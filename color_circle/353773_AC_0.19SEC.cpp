#include <iostream>
#define L 1000000003
using namespace std;
unsigned long long dp[1001][1001]={0};
unsigned long long dp2[1001][1001]={0};
int main() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) dp[1][i] = 1;
    for(int i=2;i<=k;i++) {
        for(int j=i*2-1;j<=n-1;j++) {
            dp[i][j]=dp[i][j-1]%L+dp[i-1][j-2]%L;     
        }
    }
     
    for(int i=2;i<=n;i++) dp2[1][i] = 1;
    for(int i=2;i<=k;i++) {
        for(int j=i*2;j<=n;j++) {
            dp2[i][j]=dp2[i][j-1]%L+dp2[i-1][j-2]%L;
             
        }
    }
    unsigned long long sum=0;
    for(int i=1;i<n;i++) sum+=dp[k][i];
    sum+=dp2[k][n];
    cout<<sum%L;
}