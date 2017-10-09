#include<iostream>
using namespace std;
int main() {
    int a,b,c,cnt=0,d=0;
    cin>>a>>b>>c;
    int i;
    a+=b;
    d=a/c;
    cnt=a/c;
    a=a%c;
    a+=d;
    for(i=1;;i++) {
        
        d=a/c;
        cnt+=a/c;
        a=a%c;
        a+=d;
        if(d==0) break;
    }
    cout<<cnt;
}