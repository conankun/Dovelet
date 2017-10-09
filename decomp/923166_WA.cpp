#include <stdio.h>
int primes[1000000];
int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    //for i=2
    for(i=2;i<=200000;i+=2) {
        primes[i]=1;
    }
    for(i=3;i<=200000;i++) {
        for(j=i;j<=200000;j+=i) {
            primes[j]=1;
        }
    }
    int m=n;
    for(i=2;i<=200000;i++) {
        while(m%i==0) {
            printf("%d ",i);
            m/=i;
        }
    }
}
