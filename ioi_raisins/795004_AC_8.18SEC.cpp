#include<iostream>
using namespace std;
int dp[51][51][51][51];
int hap[51][51][51][51];
int n,m;
int table[51][51];
int main() {
    int i,j,k,l,r;
scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
scanf("%d",&table[i][j]);
        }
    }
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) for(k=1;k<=n;k++) for(l=1;l<=m;l++) dp[i][j][k][l]=2147483647;
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            dp[i][j][i][j]=0;
            hap[i][j][i][j] = table[i][j];
        }
    }
    int aa = max(n,m);
    for(k=0;k<=aa;k++) {
        for(l=0;l<=aa;l++) {
            for(i=1;i<=n;i++) { //시작점.
                for(j=1;j<=m;j++) { //시작점.
                    int c=0;
                    if(i+k <= n && j+l <= m) {
                        int mn=2100000000;
                        for(r=j+l-1;r>=j;r--) {
                            if(dp[i][j][i+k][r]+dp[i][r+1][i+k][j+l] < mn) {
                                mn = dp[i][j][i+k][r]+dp[i][r+1][i+k][j+l];
                                hap[i][j][i+k][j+l] = hap[i][j][i+k][r]+hap[i][r+1][i+k][j+l];
                            }
                        }
                        for(r=i+k-1;r>=i;r--) {
                            if(dp[i][j][r][j+l]+dp[r+1][j][i+k][j+l] < mn) {
                                mn = dp[i][j][r][j+l]+dp[r+1][j][i+k][j+l];
                                hap[i][j][i+k][j+l] = hap[i][j][r][j+l]+hap[r+1][j][i+k][j+l];
                            }
                        }
                        dp[i][j][i+k][j+l] = min(mn+hap[i][j][i+k][j+l],dp[i][j][i+k][j+l]);
                    }
                    c=0;
                    if(i+l <= n && j+k <= m) {
                        int mn=2100000000;
                        for(r=j+k-1;r>=j;r--) {
                            if(dp[i][j][i+l][r]+dp[i][r+1][i+l][j+k] < mn) {
                                mn = dp[i][j][i+l][r]+dp[i][r+1][i+l][j+k];
                                hap[i][j][i+l][j+k]=hap[i][j][i+l][r]+hap[i][r+1][i+l][j+k];
                            }
                        }
                        for(r=i+l-1;r>=i;r--) {
                            if(dp[i][j][r][j+k]+dp[r+1][j][i+l][j+k] < mn) {
                                mn = dp[i][j][r][j+k]+dp[r+1][j][i+l][j+k];
                                hap[i][j][i+l][j+k]=hap[i][j][r][j+k]+hap[r+1][j][i+l][j+k];
                            }
                        }
                        dp[i][j][i+l][j+k] = min(mn+hap[i][j][i+l][j+k],dp[i][j][i+l][j+k]);
                    }
                }
            }
        }
    }
    cout<<dp[1][1][n][m];
}