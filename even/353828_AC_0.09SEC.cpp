#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    if(a > b) {
        int temp=a;
        a = b;
        b = a;
    }
     
    int aa = (int)ceil(sqrt((double)a));
    int bb = (int)ceil(sqrt((double)b));
    if(a == b) {
        int c=0;
        for(int i=1;i<=a;i++) {
            if(a%i ==0)c++;
        }
        if(c%2==0) cout<<1;
        else cout<<0;
    } else {
    cout<<b-a-bb+aa+1;
    }
    cin>>a;
}