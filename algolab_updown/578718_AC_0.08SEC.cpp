#include<stdio.h>
long long n;
int main() {
        scanf("%lld",&n);
        long long g=1,cnt=0;
        while(g<=n) {g*=2;cnt++;}
        printf("%lld",cnt-1);
}