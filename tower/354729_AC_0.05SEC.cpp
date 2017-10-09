#include<iostream>
#include<algorithm>
using namespace std;
struct A { int t,h,w,i; };
A arr[101]={0};
bool cmp(A a,A b) {
    return a.t < b.t;
}
struct B { int h,b; };
B dp[101]={0};
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i].t>>arr[i].h>>arr[i].w;
        arr[i].i = i;
    }
    sort(arr,arr+n,cmp);
    int mx=0;
    int in;
    for(int i=0;i<n;i++) {
        int b=0;
        int t=0;
        dp[i].h = arr[i].h;
        for(int j=i-1;j>=0;j--) {
            if(arr[i].t > arr[j].t && arr[i].w > arr[j].w) {
                if(b < dp[j].h) {
                    b = dp[j].h;
                    t = j+1;
                }
            }
        }
        dp[i].h += b;
        dp[i].b = t;
        if(dp[i].h > mx) {
            mx = dp[i].h;
            in = i;
        }
    }
    int t=in;
    int arr2[100]={t+1};
    in=1;
    while(dp[t].b != 0) {
        arr2[in++] = dp[t].b;
        t = dp[t].b-1;
    }
    cout<<in<<endl;
    for(int i=in-1;i>=0;i--) cout<<arr[arr2[i]-1].i+1<<endl;
}