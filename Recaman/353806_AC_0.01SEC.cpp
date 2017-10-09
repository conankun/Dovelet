#include<iostream>
using namespace std;
int c[10000000]={0};
int dp[500001]={0};
int main() {
    for(int i=1;i<=500000;i++) {
        if(dp[i-1]-i > 0 && c[dp[i-1]-i] == 0) {
            dp[i]=dp[i-1]-i;
            c[dp[i-1]-i]=1;
        } else {
            dp[i]=dp[i-1]+i;
            c[dp[i-1]+i]=1;
        }
    }
    int n;
    while(cin>>n) {
        if(n==-1)break;
        cout<<dp[n]<<endl;
    }
}