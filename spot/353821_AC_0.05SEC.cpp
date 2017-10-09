#include <iostream>
using namespace std;
int main () {
    float d,p;
    cin>>d>>p;
    if(p < 0.00) {
        d-= d*(( 100-(-p) ) / 100.00);
    } else {
        d-= d*(( 100+p ) / 100.00);
    }
     
    printf("%.3f",d);
    return 0;
}