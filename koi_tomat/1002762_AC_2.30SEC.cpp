#include <iostream>
#include<queue>
using namespace std;
int m,n;
int t[1111][1111];
int vis[1111][1111];
struct A {
    int x,y,d;
};
queue<A> qu;
int main()
{
    //n,m
    scanf("%d%d",&m,&n);
    int i,j;
    int tom=0;
    int mat=0;
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) {
            scanf("%d",&t[i][j]);
            t[i][j]++;
            if(t[i][j]>0) tom++;
            if(t[i][j]==2) {
                vis[i][j]=1;
                mat++;
                A aa;
                aa.x=j;
                aa.y=i;
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
        if(mat==tom) counts=fr.d;
        A aa;
        if(vis[y+1][x]==0 && t[y+1][x]==1) {
            vis[y+1][x]=1;
            mat++;
            aa.y=y+1;
            aa.x=x;
            aa.d=fr.d+1;
            qu.push(aa);
        }
        if(vis[y-1][x]==0 && t[y-1][x]==1) {
            vis[y-1][x]=1;
            mat++;
            aa.y=y-1;
            aa.x=x;
            aa.d=fr.d+1;
            qu.push(aa);
        }
        if(vis[y][x+1]==0 && t[y][x+1]==1) {
            vis[y][x+1]=1;
            mat++;
            aa.y=y;
            aa.x=x+1;
            aa.d=fr.d+1;
            qu.push(aa);
        }
        if(vis[y][x-1]==0 && t[y][x-1]==1) {
            vis[y][x-1]=1;
            mat++;
            aa.y=y;
            aa.x=x-1;
            aa.d=fr.d+1;
            qu.push(aa);
        }
    }
    if(mat != tom) printf("%d",-1);
   else printf("%d",counts);
}
