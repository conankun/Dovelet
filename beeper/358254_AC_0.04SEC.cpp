#include<iostream> 
#include<stdlib.h> 
using namespace std; 
int n,m; 
int sx,sy; 
int t; 
int map[121][121]={0}; 
int vis[121][121]={0}; 
int sh=999999; 
void DFS(int x,int y,int count,int length) { 
    if(count == t) { 
        sh = min(sh,length + abs(y-sy) + abs(x-sx)); 
        return; 
    } 
    vis[y][x]=1; 
    for(int i=1;i<=m;i++) { 
        for(int j=1;j<=n;j++) { 
            if(vis[i][j] == 0 && map[i][j] == 1 && abs(y-i)+abs(x-j)+length <= sh) { 
                vis[i][j]=1; 
                DFS(j,i,count+1,length+abs(y-i)+abs(x-j)); 
                vis[i][j]=0; 
            } 
        } 
    } 
    vis[y][x]=0; 
} 
int main() { 
    cin>>n>>m; 
    cin>>sx>>sy; 
    cin>>t; 
    int by=sy,bx=sx; 
    int sum=0; 
    for(int i=0;i<t;i++) { 
        int a,b; 
        cin>>a>>b;   
        map[b][a]=1; 
    } 
    DFS(sx,sy,map[sy][sx],0); 
    cout<<"The shortest path has length "<<sh; 
} 
 
