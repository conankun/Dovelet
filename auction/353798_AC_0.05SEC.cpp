#include<iostream>
#include<algorithm>
using namespace std;
int farmers[10000]={0};
int n,m;
int main() {
    cin>>n>>m;
    for(int i=0;i<m;i++) cin>>farmers[i];
    sort(farmers,farmers+m);
    int price=0,mx=0;
    for(int i=0;i<m;i++) {
        int p = m-i;
        if(p > n) p = n;
        if(farmers[i]*p > mx) {
            mx = farmers[i]*p;
            price = farmers[i];
        }
    }
    cout<<price<<" "<<mx;
}