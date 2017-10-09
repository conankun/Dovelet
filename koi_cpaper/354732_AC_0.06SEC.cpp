#include<iostream>
#include<algorithm>
using namespace std;
struct A { int a,b; };
A arr[101]={0};
int dp[101]={0};
bool cmp(A a,A b) {
    return (a.a * a.b) < (b.a*b.b);
}
int main() {
    int n;
    int max=0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i].a>>arr[i].b;
    sort(arr,arr+n,cmp);
    for(int i=0;i<n;i++) {
        int mx=0;
        for(int j=i-1;j>=0;j--) {
            if((arr[i].a >= arr[j].a && arr[i].b >= arr[j].b) || (arr[i].a >= arr[j].b && arr[i].b >= arr[j].a)) {
                if(dp[j] > mx) mx = dp[j];
            }
        }
        dp[i] = mx+1;
        if(dp[i] > max) max = dp[i];
    }
    cout<<max;
}