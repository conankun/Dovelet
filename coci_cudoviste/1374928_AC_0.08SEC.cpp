#include<stdio.h>
int n,m;
char c[100][100];
int map[100][100];
int dp[10][100][100];
int max(int a,int b) {
    if(a>b) return a;
    return b;
}
int main() {
    scanf("%d%d\n",&n,&m);
    int i,j,k;
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            scanf("%c",&c[i][j]);
            if(c[i][j]=='X')map[i][j] = 1;
        }
        if(i!= n)scanf("\n");
    }
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            if(j-1 < 1 || i-1 < 1) continue;
            int cars = map[i][j]+map[i-1][j]+map[i-1][j-1]+map[i][j-1];
            int token=1;
            if(c[i][j] == '#' || c[i][j-1]=='#' || c[i-1][j] == '#' || c[i-1][j-1] == '#') {
                token=0;
            }
            dp[cars][i][j]=token;
            
        }
    }
    // 매치
    //단독
    int ans[10]={0};
    for(k=0;k<=4;k++)
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            ans[k]+=dp[k][i][j];
            
            
        }
    }
    printf("%d\n%d\n%d\n%d\n%d\n",ans[0],ans[1],ans[2],ans[3],ans[4]);
    
    
}