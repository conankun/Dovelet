#include <iostream>
using namespace std;
unsigned long long C(int n,int r) {
    unsigned long long bc[32][32];
    for(int i=0;i<=n;i++) bc[i][0]=1;
    for(int j=0;j<=n;j++) bc[j][j]=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<i;j++) {
            bc[i][j] = bc[i-1][j-1]+bc[i-1][j];
        }
    }
    return bc[n][r];
}
int main() {
    unsigned long long dp[32]={0};
    unsigned long long n,m;
    cin>>n>>m;
    dp[0]=1;
    for(unsigned long long i=1;i<=m;i++) {
        //dp[i] = dp[i-1] + nCi
        dp[i] = dp[i-1]+C(n,i);
    }
    cout<<dp[m];
}