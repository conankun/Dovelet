#include<iostream>
#include<algorithm>
using namespace std;
struct A {
    int l,m;
};
bool cmp(A a,A b) {
    if(a.l == b.l) {
        return a.m < b.m;
    }
    return a.l < b.l;
}
A arr[10000]={0};
int dp[10000]={0};
int mx=0;
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i].l>>arr[i].m;
    sort(arr,arr+n,cmp);
    dp[0]=1;
    for(int i=1;i<n;i++) {
        int m=0;
        for(int j=i-1;j>=0;j--) {
            if(dp[j] > m && arr[j].l <= arr[i].l && arr[j].m <= arr[i].m) m = dp[j];
        }
        dp[i] = m+1;
        if(dp[i] > mx) mx = dp[i];
    }
    cout<<mx;
}