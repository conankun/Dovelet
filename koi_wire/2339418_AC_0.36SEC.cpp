#include <stdio.h>
#include <algorithm>
using namespace std;
int btk[1000010];
int dp[1000010];
int out[1000010];
int che[1000010];

struct jungitjul{
    int left, right, lcs, in;
    bool operator < (const jungitjul & jj) const {
        return left < jj.left;

    }
}jungi[1000010];

struct rightsort{
    int value, index;

}tree[4000010];

int main(){
    int wires, i, j, sizes, totalindex=-1;
    scanf("%d", &wires);
    for(i=1;i<=wires;i++){
        scanf("%d", &jungi[i].left);
        if(totalindex<jungi[i].left){
            totalindex = jungi[i].left;
        }
        scanf("%d", &jungi[i].right);
        jungi[i].in = i;
        jungi[i].lcs =0;
    }
    sort(jungi+1, jungi+wires+1);
    for(sizes=1;sizes<500000;sizes*=2);

    int ans=0, ind2=-1;
    for(i=1;i<=wires;i++){
        int le = sizes, ri = sizes+jungi[i].right-1;
        int mx = 0, ind = 0;
        bool cer= true;
        while(le<=ri && cer){
            if(le == ri){
                cer= false;
            }
            if(le%2 ==1){
                if(tree[le].value>mx){
                    mx = tree[le].value;
                    ind = tree[le].index;
                }
                le++;
            }
            if(ri%2 == 0){
                if(tree[ri].value>mx){
                    mx = tree[ri].value;
                    ind = tree[ri].index;
                }
                ri--;
            }
            le/=2;
            ri/=2;
        }
        btk[i]=ind;
        dp[i]=mx+1;
        if(ans<mx+1){
            ans = mx+1;
            ind2 = i;
        }
        int in = sizes+jungi[i].right;
        while(in>0){
            if(tree[in].value <mx+1){
                tree[in].value = mx+1;
                tree[in].index = i;
            }
            in/=2;
        }
    }

    int checked = ind2;
    che[ind2] =1;
    while(checked>0){
        checked= btk[checked];
        che[checked] = 1;
    }
    int cnt =0;
    for(i=1;i<=wires;i++){
        if(che[i]==0){
            cnt++;
            out[cnt] = jungi[i].left;
        }
    }
    printf("%d\n", cnt);
    sort(out+1, out+cnt+1);
    for(i=1;i<=cnt;i++){
        printf("%d\n", out[i]);
    }
    return 0;
}
