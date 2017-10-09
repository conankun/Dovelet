#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> btk2;
int arr[500010], btk[500010], k[500010], k2[500010], di[500010];
int max(int x, int y){
    if (x > y)
        return x;
    return y;
}
struct lis{
int value, index;
bool operator<(const lis &ll) const {
    return value < ll.value;
}
}arr2[500010];
lis kni[1500000];
int main(){
    int i, n,m, sizes=1;
    scanf("%d", &n);
    for (i=1; i <= n; i++){
        scanf("%d", &arr[i]);
        arr2[i].index = i;
        arr2[i].value = arr[i];
    }
    for(sizes=1;sizes<n;sizes*=2);
    sort(arr2+1, arr2+1+n);
    for(i=1;i<=n;i++){
        k[i] = (arr2[i].value == arr2[i-1].value ? 0:1) + k[i-1];
        k2[arr2[i].index] = k[i];
    }
    int ans=0,in2;
    for(i=1;i<=n;i++){
        int l = sizes +1, r = sizes+k2[i]-1;
        bool t = true;
        int maxx=0;
        int in=0;

        while(l<=r && t){
            if(l==r){
                t = false;
            }
            if(l%2 == 1){
                if(kni[l].value> maxx){
                    maxx = kni[l].value;
                    in = kni[l].index;
                }
            }
            if(r%2==0){
                if(kni[r].value>maxx){
                    maxx = kni[r].value;
                    in = kni[r].index;
                }
            }
        l/=2;
        r/=2;
        }
         di[i]=maxx+1;
         btk[i] = in;
         if(di[i]>ans){
            ans = di[i];
            in2 = i;
         }
        r = sizes + k2[i];
         while(r > 0){
            if(kni[r].value<maxx+1){
                kni[r].value = maxx+1;
                kni[r].index = i;
            }
            r /=2;
         }
    }
    printf("%d\n", ans);
    btk2.push_back(in2);
    while(btk[in2]>0){
        btk2.push_back(btk[in2]);
        in2 = btk[in2];
    }
    for(i=btk2.size()-1;i>=0;i--){
        printf("%d ", arr[btk2[i]]);
    }

    return 0;
}
