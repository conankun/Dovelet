#include <stdio.h>
long long n;
long long A[2000][2000];
long long min(long long a,long long b) {
    if(a>b) return b;
    return a;
}
long long sum;
int main()
{
    scanf("%lld",&n);
    long long i,j;
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            scanf("%lld",&A[i][j]);
        }
    }
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            sum+=min(i,min(j,min(n+1-i,n+1-j)))*A[i][j];
        }
    }
    printf("%lld",sum);
}

