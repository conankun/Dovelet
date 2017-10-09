#include<iostream>
#include<stdio.h>
using namespace std;
int circle[101][101];
int dp[101][101];
int max(int a,int b) {
    if(a > b) return a;
    return b;
}
int main() {
    int i, j, n, a, b, k,z;
    scanf("%d", &n);
    for(i=1;i<=n;i++) {
        scanf("%d %d", &a, &b);
        if(b < a) {
            int temp = a;
            a = b;
            b = temp;
        }
        circle[a][b]=1;
    }
    for(k=1;k<=100;k++) {
        for(i=1;i<=100-k+1;i++) {
            j = i+k-1;
            for(z=i;z<=j-1;z++) {
                dp[i][j]=max(dp[i][z]+dp[z+1][j]+circle[z][j],dp[i][j]);
            }
        }
    }
    printf("%d", dp[1][100]);
}
