#include<iostream>
using namespace std;
int n;
int data[200];
int dp[200];
int dp2[200];
int main() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>data[i];
    int mx=0;
    //LIS
    dp[0]=1;
    for(int i=0;i<n;i++) {
        dp[i]=1;
        for(int j=i-1;j>=0;j--) {
            if(data[j] < data[i] && dp[j]+1 > dp[i]) {
                dp[i] = dp[j]+1;
            }
        }
        if(dp[i] > mx) mx = dp[i];
    }
 
    cout<<n-mx;
}