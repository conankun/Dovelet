#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int field[200][200];
int wcount =0, pcount =0;
void split(int xstart, int ystart, int xend, int yend){
    int i, j, uneq =0, k;
    k = field[xstart][ystart];
    for(i=ystart;i<=yend;i++){
        for(j=xstart;j<=xend;j++){
            if(field[j][i] != k){
                uneq =1;
                break;
            }
        }
    }
    if(uneq ==1){
        split(xstart, ystart, ((xend-xstart)/2)+xstart, ((yend-ystart)/2)+ystart);
        split(((xend-xstart)/2)+xstart+1, ystart, xend, ((yend-ystart)/2)+ystart);
        split(xstart, ((yend-ystart)/2)+ystart+1, ((xend-xstart)/2)+ xstart, yend);
        split(((xend-xstart)/2)+xstart+1, ((yend-ystart)/2)+ystart+1, xend, yend);
    }else{
        if( k ==1 ){
            pcount++;
        }else{
            wcount++;
        }
    }



}
int main(){
    int n, i, j;
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d", &field[i][j]);
        }
    }
    split(1,1,n,n);

    printf("%d\n%d", wcount, pcount);
return 0;
}






