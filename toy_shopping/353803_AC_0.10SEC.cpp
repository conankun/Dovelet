#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct A {
    double r;
    int b;
    int index;
};
A arr[25001];
bool cmp(A a,A b) {
    return a.r > b.r;
}
int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        arr[i].r=(a == 0 || b == 0) ? 0 : (double)a/b;
        arr[i].b = b;
        arr[i].index = i+1;
    }
    sort(arr,arr+n,cmp);
    int sum=0;
    for(int i=0;i<3;i++) sum+=arr[i].b;
    cout<<sum<<endl;
    for(int i=0;i<3;i++) cout<<arr[i].index<<endl;
}