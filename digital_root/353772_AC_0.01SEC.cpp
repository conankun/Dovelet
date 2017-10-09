#include <iostream>
using namespace std;
 
int hap(int n) {
    int sum=0;
    for(;;) {
        if(n<=0) break;
        else {
            sum+=n%10;
            n/=10;
        }
    }
 
    return sum;
}
 
int main() {
    char a[1001];
     
    while(cin>>a) {
    if(a[0] == '0') break;
    int c=0;
    for(int i=0;;i++) {
        if(a[i] == NULL) break;
        c+=a[i]-'0';
         
    }
 
    if(c<10) cout<<c<<endl;
    else {
        int d=hap(c);
        if(d < 10) cout<<d<<endl;
        else {
            while(1) {
                if(hap(d) < 10) {
                    cout<<hap(d)<<endl;
                    break;
                }
            }
        }
    }
 
    }
 
 
}