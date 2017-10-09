#include <iostream>
#include<queue>
using namespace std;
int m,n,h;
int t[111][211][211];
int vis[111][211][211];
struct A {
    int x,y,h,d;
};
queue<A> qu;
int main()
{
    //n,m
    scanf("%d%d%d",&m,&n,&h);
    int i,j,k;
    int tom=0;
    int mat=0;
    for(k=1;k<=h;k++)
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            scanf("%d",&t[k][i][j]);
            t[k][i][j]++;
            if(t[k][i][j]>0) tom++;
            if(t[k][i][j]==2) {
                vis[k][i][j]=1;
                mat++;
                A aa;
                aa.x=j;
                aa.y=i;
                aa.h=k;
                aa.d=0;
                qu.push(aa);
            }
        }
    }
    int counts=0;
    while(!qu.empty()) {
        A fr = qu.front();
        qu.pop();
        
        int x=fr.x;
        int y=fr.y;
        k=fr.h;
        if(mat==tom) counts=fr.d;
        A aa;
        if(vis[k][y+1][x]==0 && t[k][y+1][x]==1) {
            vis[k][y+1][x]=1;
            mat++;
            aa.y=y+1;
            aa.x=x;
            aa.h=k;
            aa.d=fr.d+1;
            qu.push(aa);
        }
        if(vis[k][y-1][x]==0 && t[k][y-1][x]==1) {
            vis[k][y-1][x]=1;
            mat++;
            aa.y=y-1;
            aa.x=x;
            aa.h=k;
            aa.d=fr.d+1;
            qu.push(aa);
        }
        if(vis[k][y][x+1]==0 && t[k][y][x+1]==1) {
            vis[k][y][x+1]=1;
            mat++;
            aa.y=y;
            aa.x=x+1;
            aa.h=k;
            aa.d=fr.d+1;
            qu.push(aa);
        }
        if(vis[k][y][x-1]==0 && t[k][y][x-1]==1) {
            vis[k][y][x-1]=1;
            mat++;
            aa.y=y;
            aa.x=x-1;
            aa.h=k;
            aa.d=fr.d+1;
            qu.push(aa);
        }
        if(vis[k+1][y][x]==0 && t[k+1][y][x]==1) {
            vis[k+1][y][x]=1;
            mat++;
            aa.y=y;
            aa.x=x;
            aa.h=k+1;
            aa.d=fr.d+1;
            qu.push(aa);
        }
        if(vis[k-1][y][x]==0 && t[k-1][y][x]==1) {
            vis[k-1][y][x]=1;
            mat++;
            aa.y=y;
            aa.x=x;
            aa.h=k-1;
            aa.d=fr.d+1;
            qu.push(aa);
        }
    }
    if(mat != tom) printf("%d",-1);
   else printf("%d",counts);
}
