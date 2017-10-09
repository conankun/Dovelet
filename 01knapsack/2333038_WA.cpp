#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
int field[10010];
int weight[110];
int price[110];
struct bosuk{
    int weight, price;
}bos[101];
int main(){
    int knap, types, i, j, w, p, k;
    scanf("%d %d", &knap, &types);
    for(i=0;i<types;i++){
        scanf("%d %d", &w, &p);
        bos[i].weight = w;
        bos[i].price = p;
    }
    for(j=1;j<=types;j++){
        for(k=knap;k>=0;k--){
            if(k+bos[j].weight> knap){
                continue;
            }
            if(bos[j].price + field[k]> field[k+bos[j].weight]){
                field[k+bos[j].weight] = field[k] + bos[j].price;
            }
        }
    }
    int eduk=-1;
    for(i=0;i<=knap;i++){
        if(field[i]>eduk){
            eduk = field[i];
        }
    }
    printf("%d", eduk);
    return 0;
}
