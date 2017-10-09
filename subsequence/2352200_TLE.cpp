#include <iostream>
#include <stdio.h>
using namespace std;
int field[500100];
int ans=0, gugan=-1;
int n;
void bsearch(int low, int high){
    int i, mid, sum=0, check=0;
    mid = (low+high)/2;
    if(low>high){
        return;
    }
    for(i=1;i<=mid;i++){
        sum += field[i];
    }
    for(i=mid+1;i<=n;i++){
        if(sum >= ans){
            if(mid < gugan|| gugan ==-1){
                gugan = mid;
        }
            bsearch(low, mid-1);
            check=1;
        }
        sum = sum+field[i] - field[i-mid];
        if(sum >= ans){
            if(mid < gugan|| gugan ==-1){
                gugan = mid;
            }
            bsearch(low, mid-1);
            check =1;
        }
        if(check ==0){
            bsearch(mid+1, high);
        }
    }

}
int main (){
    int i, goal, fin;
    scanf("%d %d", &n, &ans);
    for(i=1;i<=n;i++){
        scanf("%d", &field[i]);
    }
    bsearch(1, n);
    printf("%d", gugan);
return 0;
}
