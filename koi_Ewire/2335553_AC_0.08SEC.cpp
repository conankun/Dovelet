#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
/* 5
72 297
400 223
273 13
195 227
198 400
3
*/
int left[1100];
int right[1100];
int dp[1100];
struct jungitjul{
    int left, right, lcs;
    bool operator < (const jungitjul & jj) const {
        return left < jj.left;

    }
}jungi[1100];
int main(){
    int wires, i, j, mx=0;
    scanf("%d", &wires);
    for(i=0;i<wires;i++){
        scanf("%d", &jungi[i].left);
        scanf("%d", &jungi[i].right);
        jungi[i].lcs =0;
    }
    sort(jungi, jungi+wires);
    dp[0] = 0;
    for(i=0;i<wires;i++){
        for(j=0;j<i;j++){
            if(jungi[i].right >= jungi[j].right){
                jungi[i].lcs = max(jungi[i].lcs, (jungi[j].lcs)+1);
            }
        }
    }
    for(i=0;i<wires;i++){
        if(jungi[i].lcs>mx){
            mx = jungi[i].lcs;
        }
    }
    printf("%d", wires - (mx+1));

    return 0;
}
