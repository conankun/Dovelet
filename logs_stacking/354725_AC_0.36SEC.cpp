#include<iostream>
using namespace std;
unsigned long long dp[1000000]={1,1};
int main() {
    int n;
    cin>>n;
    for(int i=2;i<=100000;i++) {
        unsigned long long a = (dp[i-1]+100000)*3 - dp[i-2];
        dp[i] = a%100000;
    }
    cout<<dp[n%75000];
}