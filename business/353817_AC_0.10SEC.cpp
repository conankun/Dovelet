#include <iostream>
using namespace std;
int main () {
    int a,b,c,d;
    int pm,rm,gm;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    pm = b+d;
    rm = pm-c;
    gm = a-(rm-d);
     
    printf("%d",gm);
     
     
    return 0;
}