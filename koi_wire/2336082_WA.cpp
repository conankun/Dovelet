#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
int btk[500010];
int out[500010];

struct jungitjul{
    int left, right, lcs;
    bool operator < (const jungitjul & jj) const {
        return left < jj.left;

    }
}jungi[500010];
jungitjul tree[500010];
struct rightsort{
    int value, index;
    bool operator < (const rightsort & rs) const{
        return value < rs.value;
    }

}sortedright[500010];
int k[500010];
int main(){
    int wires, i, j, sizes, totalindex=-1;
    scanf("%d", &wires);
    for(i=0;i<wires;i++){
        scanf("%d", &jungi[i].left);
        if(totalindex<jungi[i].left){
            totalindex = jungi[i].left;
        }
        scanf("%d", &jungi[i].right);

        jungi[i].lcs =0;
    }
    sort(jungi, jungi+wires);
    for(i=0;i<wires;i++) {
        sortedright[i+1].value = jungi[i].right;
        sortedright[i+1].index = i;
    }
    sort(sortedright+1, sortedright+wires+1);
    for(sizes=1;sizes<wires;sizes*=2);
    int cnt = 0;
    for(i=1;i<=wires;i++){
        if(sortedright[i].value != sortedright[i-1].value){
            cnt++;
        }
        k[sortedright[i].index] = cnt;
    }
    int ans=0, ind=0, ind2=0;
    for(i=0;i<wires;i++){
        int le = sizes, ri = sizes+k[i]-1;
        int mx = 0;
        bool cer= true;
        while(le<=ri && cer){
            if(le == ri){
                cer= false;
            }
            if(le%2 ==1){
                if(tree[le].lcs>mx){
                    mx = tree[le].lcs;
                    ind = tree[le].right;
                }
            le++;
            }
            if(ri%2 == 0){
                if(tree[ri].lcs>mx){
                    mx = tree[ri].lcs;
                    ind = tree[ri].right;
                }
            ri--;
            }
        le/=2;
        ri/=2;
        }
        jungi[i].lcs = mx+1;
        btk[i]=ind;
        if(ans<mx+1){
            ans = mx+1;
            ind2 = i;
        }
        int in = sizes+k[i];
        while(in>0){
            if(tree[in].lcs <mx+1){
                tree[in].lcs = mx+1;
                tree[in].right = i;
            }
            in/=2;
        }
    }
    printf("%d\n", wires-ans);
    while(btk[ind2]>0){
        out[jungi[ind2].left] = 1;
        ind2= btk[ind2];
    }
    out[jungi[ind2].left] = 1;
    for(i=0;i<wires;i++){
        if(out[jungi[i].left]==1){
            continue;
        }else{
            printf("%d\n", jungi[i].left);
        }
    }
   // printf("%d", wires - (mx));

    return 0;
}
