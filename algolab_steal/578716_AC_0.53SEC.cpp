#include<stdio.h>
int dp[222][222][222];
int map[1000][1000];
int max(int a,int b) {
    if(a>b) return a;
    return b;
}
int main() {
    int N;
    scanf("%d",&N);
    int i,j,k;
    for(i=1;i<=N;i++) for(j=1;j<=N;j++) {scanf("%d",&map[i][j]);map[i][j]=map[i][j-1]+map[i][j];}
    int mx=0;
    for(i=1;i<=N;i++) {
        for(j=1;j<=N;j++) {
            for(k=1;k<=j;k++) {
                int g=map[i][j]-map[i][k-1];
                dp[i][j][k]=max(dp[i-1][j][k]+g,g);
                if(dp[i][j][k]>mx) mx=dp[i][j][k];
            }
        }
    }
    printf("%d",mx);
}