#include<iostream>
using namespace std;
int main() {
    int l1,l2;
    int L1[181];
    int L2[181];
    int dp[181][181]={0};
    cin>>l1>>l2;
    for(int i=1;i<=l1;i++) cin>>L1[i];
    for(int i=1;i<=l2;i++) cin>>L2[i];
 
    int mx=0;
    for(int i=1;i<=l2;i++) {
        for(int j=1;j<=l1;j++) {
            if(L1[j] == L2[i]) {
            dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j]=0;
            }
            if(dp[i][j] > mx) mx = dp[i][j];
        }
    }
    cout<<mx;
}