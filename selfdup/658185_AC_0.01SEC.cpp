#include<stdio.h>
int main(){
    int i,j;
    j=10;
    for(i=1;i<=10000;i++){
        if(i==10||i==100||i==1000||i==10000)j*=10;
        if((i*i)%j==i) {
            printf("%d\n",i);
        }
    }
}