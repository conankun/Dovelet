#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int n;
int ans=-1;
int cnt;
int dis[1000000][100];
int field [100][100];
int main (){
    scanf("%d", &n);
    int i, j, l, k, lim=1, jk=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d", &field[i][j]);
        }
    }
    for(i=1;i<=(1<<n)-1;i++){
        for(j=1;j<=n;j++){
            dis[i][j]=999999999;
        }
    }
    dis[1][1]= 0;
    for(i=2;i<=n;i++){
        for(k=0;k<(1<<n);k++){
            cnt=0;
            jk = k;
            while(jk>0){
                if(jk%2==1){
                    cnt++;
                }
                jk/=2;
            }
            if(i == cnt){
                for(j=1;j<=n;j++){
                    for(l=1;l<=n;l++){
                        if(j==l){
                            continue;
                        }
                        if((k&(1<<(j-1)))==0){
                            continue;
                        }
                        if((k&(1<<(l-1)))==0){
                            continue;
                        }
                        if(field[l][j]==0){
                            continue;
                        }

                        dis[k][j] = min(dis[k-(1<<(j-1))][l]+field[l][j], dis[k][j]);
                        if(cnt == n){
                            if(field[j][1]==0){
                                continue;
                            }
                            if(ans==-1|| dis[k][j]+field[j][1]<ans){
                                ans = dis[k][j]+field[j][1];

                            }
                        }
                    }
                }
            }

        }
    }
printf("%d", ans);


return 0;
}
