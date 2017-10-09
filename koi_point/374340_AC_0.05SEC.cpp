#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    int g=abs(a-b);
    while(!(g%2) && g > 0) {
        g/=2;
    }
    int i;
    for(i=0;i<5;i++) {
        int c,d;
        cin>>c>>d;
        if(a == b) {
            if(c == d) cout<<"Y"<<endl;
			else cout<<"N"<<endl;
        } else {
            if(c == d || (a-b)*(c-d) < 0) {
                cout<<"N"<<endl;
            } else if(abs(c-d)%g == 0) cout<<"Y"<<endl; 
            else cout<<"N"<<endl;
        }
    }
}