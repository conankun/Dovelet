#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> btk2;
int weight[1010];
int price[1010];
struct bosuk{
    int weight, price;
    bool operator < (const bosuk& le)const{
        return price/(double)weight > le.price/(double)le.weight;
    }
}bos[1010];
int main(){
    int knap, types, i, j, w, p;
    double eduk=0;
    scanf("%d %d", &knap, &types);
    for(i=0;i<types;i++){
        scanf("%d %d", &w, &p);
        bos[i].weight = w;
        bos[i].price = p;
    }
    sort(bos, bos+types);
    for(j=0;j<types;j++){
        if(knap < bos[j].weight){
            eduk += (bos[j].price / (double)bos[j].weight)*(knap);
            knap = 0;
        }else{
            knap -= bos[j].weight;
            eduk += bos[j].price;
        }
    }
    printf("%.2lf", eduk);
    return 0;
}
