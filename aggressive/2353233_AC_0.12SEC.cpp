#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int slot, cow, md=0;
int field[1000110];
void bsearch(int low, int high){
    int mid, j, cnt=1, st = field[1];
    mid = (low+high)/2;
    if(low<=high){
        for(j=2;j<=slot;j++){
            if(field[j] - st< mid){
                continue;
            }
            else {
                cnt++;
                st = field[j];
            }
            if(cnt>=cow){
                break;
            }
        }
        if(cnt >= cow){
            if(mid>md){
                md = mid;
            }
            bsearch(mid+1, high);
        }
        else{
            bsearch(low, mid-1);
        }

    }
}

int main (){
int i;
scanf("%d %d", &slot, &cow);
for(i=1;i<=slot;i++){
    scanf("%d", &field[i]);
}
sort(field+1, field+1+slot);
bsearch(1,field[slot]);
printf("%d", md);
return 0;
}
