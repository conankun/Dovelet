#include<iostream>
#include<cmath>
using namespace std;
int roundoff(int n,int mod) {
    int a=n%mod;
    if(a >=5) {
        return n+mod-a;
    } else {
        return n-a;
    }
}
int main() {
    int a,b;
    cin>>a>>b;
    int c=pow(10,b);
    if(c>a) cout<<0;
    else
    cout<<roundoff(a,c);
}