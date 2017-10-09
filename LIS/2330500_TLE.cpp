#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
vector<int> btk2;
int arr[500010], btk[500010], d[500010];
int max(int x, int y){
    if (x > y)
        return x;
    return y;
}
void us(int len){
    int i, j, k, dis=0, maxs, index2;
    d[1] = 1;
    int ans =0;
    for(i=1;i<=len;i++){
        maxs=0;
        int index =0;
        for(j=1;j<=i;j++){
            if(arr[i]> arr[j] && d[j]>maxs){
                maxs = d[j];
                index = j;
            }
        }
        d[i] = maxs+1;
        btk[i] = index;
        if(d[i]> ans){
            ans = d[i];
            index2 = i;
        }
    }
    printf("%d\n", ans);

    btk2.push_back(index2);
    while(btk[index2]>0){
        btk2.push_back(btk[index2]);
        index2 = btk[index2];
    }
    for(i=btk2.size()-1;i>=0;i--){
        printf("%d ", arr[btk2[i]]);
    }

}
int main(){
    int i, n,m;
    scanf("%d", &n);
    for (i=1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    us(n);


    return 0;
}
