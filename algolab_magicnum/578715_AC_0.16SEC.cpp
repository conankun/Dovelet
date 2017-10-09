#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main() {
    long long n;
    long long cnt=0;
    scanf("%lld",&n);
    long long g=1;
    while(g<n) {
        g*=10;
        long long i;
        for(i=1;i*i<=g;i++) {
            if(g%i==0) {
                long long a=g/i;
                if(a<=n && a>g/10)cnt++;
                if(a != i && i<=n && i>g/10) cnt++;
            }
        }
    }
    printf("%lld",cnt+1);
}