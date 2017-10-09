#include<iostream>
using namespace std;
int data[30001];
int dp[30001][4]={0};
int dp2[30001][4]={0};
int n;
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>data[i];
    for(int i=1;i<=n;i++) {
        if(i != data[1]) {
            dp[1][i] = 1;
            dp2[1][i] = 1;
        }
    }
    //오름차순.
    for(int i=2;i<=n;i++) {
        dp[i][1] = dp[i-1][1]+(data[i] == 1 ? 0 : 1);
        dp[i][2] = min(dp[i-1][1],dp[i-1][2])+(data[i] == 2 ? 0 : 1);
        dp[i][3] = min(dp[i-1][1],min(dp[i-1][2],dp[i-1][3]))+(data[i] == 3 ? 0 : 1);
    }
    //내림차순
    for(int i=2;i<=n;i++) {
        dp2[i][1] = min(dp2[i-1][1],min(dp2[i-1][2],dp2[i-1][3]))+(data[i] == 1 ? 0 : 1);
        dp2[i][2] = min(dp2[i-1][3],dp2[i-1][2])+(data[i] == 2 ? 0 : 1);
        dp2[i][3] = dp2[i-1][3]+(data[i] == 3 ? 0 : 1);
    }
    cout<<min(min(dp[n][1],min(dp[n][2],dp[n][3])), min(dp2[n][1],min(dp2[n][2],dp2[n][3])));
}