#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int in[1000];
vector <int> sz;
struct cr{
int value, btk;
}dp[1000][1000];
int ggcha(int start, int fin){
int cha=0, mx = -1, mn=501, i;
for(i=start;i<=fin;i++){
    if(in[i]> mx){
        mx = in[i];
    }
    if(in[i]<mn){
        mn = in[i];
    }
}
    cha = mx-mn;
return cha;
}
int main(){
    int n, i, j, k, cmp;
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        scanf("%d", &in[i]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            dp[i][j].value = ggcha(i, j);
            if(i==j){
                dp[i][j].value = 0;
            }
        }
    }
    for(i=2;i<=n;i++){
        for(j=0;j<=n-i+1;j++){
            for(k=2+j;k<i+j-1;k++){
                cmp = dp[j+1][i+j].value;
                if(dp[j+1][k].value+dp[k+1][i+j].value >= dp[j+1][i+j].value){
                    dp[j+1][i+j].value = dp[j+1][k].value+dp[k+1][i+j].value;
                    dp[j+1][i+j].btk = k;
                }
            }
        }
    }
    int loc = n;
    int cnt = 1;
    while (loc > 0){
        cnt++;
        sz.push_back(loc - dp[1][loc].btk);
        loc = dp[1][loc].btk;
    }
    printf("%d\n", dp[1][n].value);
    printf("%d\n", sz.size());
    for(i=sz.size()-1;i>=0;i--){
        printf("%d ", sz[i]);
    }
    return 0;
}
