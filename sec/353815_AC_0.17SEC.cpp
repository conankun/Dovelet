#include <iostream>
using namespace std;
int main () {
    int sec;
     
    int d=0,h=0,m=0,s=0;
     
    scanf("%d",&sec);
     
    d = sec/(60*60*24);
    h = (sec-(d*(60*60*24)) ) / (60 * 60);
    m = (sec-(d*(60*60*24)) - (h*(60*60)) ) / 60;
    s = (sec-(d*(60*60*24)) - (h*(60*60)) - (m*60) );
     
    printf("%d %d %d %d",d,h,m,s);
     
     
     
    return 0;
}