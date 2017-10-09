#include<iostream>
#include<algorithm>
using namespace std;
struct A {
    int index;
    int t,s;
};
bool cmp(A aa,A bb) {
    if((double)aa.s/aa.t == (double)bb.s/bb.t) {
        return aa.index < bb.index;
    }
    return (double)aa.s/aa.t > (double)bb.s/bb.t;
}
A a[2000];
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i].t>>a[i].s;
        a[i].index = i+1;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++) {
        cout<<a[i].index<<" ";
    }
}