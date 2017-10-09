#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int glob=1;
void power (int base, int pow){
int split =0;
split = pow/2;
    if(pow %2 ==1){
        glob *= base;
        power(base, pow-1);
    }
    else if(pow >1){
        power(base, split);
        power(base, split);
    }else if(pow ==1){
        glob *= base;
    }
 }
int main(){
    int base, pow;
    scanf("%d %d", &base, &pow);
    power(base, pow);

    printf("%d", glob);
return 0;
}






