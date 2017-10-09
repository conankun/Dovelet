#include <iostream>
using namespace std;
int main () {
    int pc,printer,router;
    float amperes;
    int o=0;
    scanf("%d %d %d",&pc,&printer,&router);
    amperes = (pc*2.5)+(printer * 2.0)+(router * 0.5);
        if((int)amperes%10 == 0 || (int)amperes%10 == 5) {
            if((pc % 2 == 0 && router % 2 == 0) || (pc %2 == 1 && router%2 == 1)) {
        o = (int)amperes*2;
        } else {
            o = (int)amperes*2+10;
        }
         
    } else {
        o = ( ((int)amperes*2/10)+1 );
        o*=10;
    }
    printf("%d amperes",o);
    return 0;
}