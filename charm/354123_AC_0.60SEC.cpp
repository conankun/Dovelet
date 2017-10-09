#include<iostream>
using namespace std;
struct A {int wi,di;};
A arr[10000]={0};
int n,m;
int dp[100000]={0};
int main() {cin>>n>>m;for(int i=0;i<n;i++) {cin>>arr[i].wi>>arr[i].di;}dp[0]=1;int mx=0;for(int i=0;i<n;i++) {for(int j=13000;j>=0;j--) {if(dp[j] != 0 && j+arr[i].wi <= m) {dp[j+arr[i].wi] = max(dp[j+arr[i].wi],dp[j]+arr[i].di);if(dp[j+arr[i].wi] > mx) mx = dp[j+arr[i].wi];}}}cout<<mx-1;}