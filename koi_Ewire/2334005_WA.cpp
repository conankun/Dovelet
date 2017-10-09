#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
int field[1100];
int dp[1100];
struct bosuk{
    int weight, price;
}bos[101];
int main(){
    int wires, i, j, k, a, b, mx=0;
    scanf("%d", &wires);
    for(i=0;i<wires;i++){
        scanf("%d", &a);
        scanf("%d", &field[a]);
    }
    dp[0] = 0;
    for(i=1;i<=wires;i++){
        for(j=1;j<=i;j++){
            if(field[i]>=field[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    for(i=0;i<wires;i++){
        if(dp[i]>mx){
            mx = dp[i];
        }
    }
    printf("%d", wires - (mx));

    return 0;
}
