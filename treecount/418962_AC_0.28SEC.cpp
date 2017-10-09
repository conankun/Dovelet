#include<stdio.h>
long long dp[100];
long long n;
int main() {
scanf("%lld",&n);
dp[0]=1;
dp[1]=1;
long long i,j;
for(i=2;i<=n;i++) {
for(j=0;j<=i-1;j++) {
dp[i]+=dp[j]*dp[i-1-j];
}
}
printf("%lld",dp[n]);
}