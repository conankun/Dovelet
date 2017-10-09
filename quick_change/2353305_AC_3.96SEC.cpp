#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int quart=0, dime=0, nick=0, pen=0, tot, leftov=0;
int field[1000110];

int main (){
int i;
scanf("%d", &tot);
while(tot!=0){
    if(tot >= 25){
        quart=tot/25;
        tot = tot - quart*25;
    }
    if(tot>= 10){
        dime = tot/10;
        tot = tot - dime*10;
    }
    if(tot >= 5){
        nick = tot/5;
        tot = tot - nick*5;
    }
    if(tot >= 1){
        pen = tot;
        tot = tot - pen;
    }
}
printf("%d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)", quart, dime, nick, pen);

return 0;
}