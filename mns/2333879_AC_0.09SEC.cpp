#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
int field[110];
int weight[110];
int dp[110];
struct bosuk{
    int weight, price;
}bos[101];
int main(){
    int i, j, bridges, mx=-1;
    scanf("%d", &bridges);
    for(i=0;i<bridges;i++){
        scanf("%d ", &field[i]);
    }
    dp[0] = 0;
    for(i=0;i<bridges;i++){
        for(j=0;j<i;j++){
            if(field[i]>=field[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    for(i=0;i<bridges;i++){
        if(dp[i]>mx){
            mx = dp[i];
        }
    }
    printf("%d", mx+1);
    return 0;
}
