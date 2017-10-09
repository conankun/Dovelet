#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct uni{
int star, fin, cnt;

}circle[100];
int main (){
    int i, j, n,a,b, mx= -1;
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        scanf("%d %d", &a, &b);
        if(a<b){
            circle[i].star = a;
            circle[i].fin = b;
        }else{
            circle[i].star = b;
            circle[i].fin = a;
        }
        circle[i].cnt = 0;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(circle[i].star > circle[j].star){
                if(circle[i].fin < circle[j].fin || circle[i].star > circle[j].fin){
                    circle[i].cnt+=1;
                }
            }else if(circle[i].fin > circle[j].fin || circle[i].fin < circle[j].star){
                circle[i].cnt+=1;
            }
        }
        if(circle[i].cnt > mx){
            mx = circle[i].cnt;
        }
    }
    printf("%d", mx);
return 0;
}
