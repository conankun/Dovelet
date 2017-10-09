#include <iostream>
using namespace std;
int main() {
    char a[8]={NULL,};
    cin>>a;
 
    int sum=0;
    int t=9;
    int bt;
    for(int i=7;i>=0;i--) {
        if(a[i] == NULL) continue;
        else {
            if(a[i] != '?') {
                sum+=(a[i]-'0')*t;
            }                                                      
            else {
                bt=t;
            }
            if(t == 9) t=3;
            else if(t == 3) t = 7;
            else t = 9;
 
        }
    }
 
    int c;
    for(int i=0;i<=9;i++) {
        if((sum+(bt*i)) % 10 == 0) {
            c = i;
        }
    }
 
    for(int i=0;i<8;i++) {
        if(a[i] == NULL) break;
        else {
            if(a[i] != '?') cout<<a[i];
            else cout<<c;
        }
    }
}