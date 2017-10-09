#include <iostream>
#include <stdio.h>
using namespace std;
int field[500100];
int ans=0;
int bsearch(int low, int high){
    int mid;
    mid = (low+high)/2;
    if(ans == field[mid]){
        return mid;
    }
    if(low == high && ans != field[mid]){
        return 0;
    }
    if(ans > field[mid]){
        low = mid+1;
    }else if(ans < field[mid]){
        high = mid-1;
    }
    bsearch(low, high);
}
int main (){
    int n, i, low, high, piv, fin;
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        scanf("%d", &field[i]);
    }
    scanf("%d", &ans);
    fin = bsearch(1, n);
    if(fin == 0){
        printf("not found");
    }else{
        printf("%d", fin);
    }


return 0;
}
