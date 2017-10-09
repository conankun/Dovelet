#include<stdio.h>
int dp[100];
int n;
int main() {
scanf("%d",&n);
dp[0]=1;
dp[1]=1;
int i,j;
for(i=2;i<=n;i++) {
for(j=0;j<=i-1;j++) {
dp[i]+=dp[j]*dp[i-1-j];
}
}
printf("%d",dp[n]);
}