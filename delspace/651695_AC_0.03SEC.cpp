#include<stdio.h>
char ge[1000000];
int main() {
    gets(ge);
    int i;
    for(i=0;i<=1001;i++) {
        if(ge[i]!=0 && ge[i] != ' ') {
            printf("%c",ge[i]);
        }
    }
}