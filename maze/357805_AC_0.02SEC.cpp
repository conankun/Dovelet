#include<iostream> 
using namespace std; 
char map[100][100]={0}; 
int vis[100][100]={0}; 
int dis = -1; 
int n,m; //|n -m 
void DFS(int i,int j,int t) { 
    if(i > n || i < 1 || j > m || j < 1) return; 
    vis[i][j]=1; 
    if(i == 1 && j == n) { 
        if(dis == -1) dis = t; 
        else dis = min(t,dis); 
    } else { 
        if(vis[i+1][j] == 0 && map[i+1][j] == '0') { 
            vis[i+1][j] = 1; 
            DFS(i+1,j,t+1); 
        } 
        if(vis[i-1][j] == 0 && map[i-1][j] == '0') { 
            vis[i-1][j]=1; 
            DFS(i-1,j,t+1); 
        } 
        if(vis[i][j+1] == 0 && map[i][j+1] == '0') { 
            vis[i][j+1]=1; 
            DFS(i,j+1,t+1); 
        } 
        if(vis[i][j-1] == 0 && map[i][j-1] == '0') { 
            vis[i][j-1]=1; 
            DFS(i,j-1,t+1); 
        } 
    } 
    vis[i][j]=0; 
} 
int main() { 
    cin>>n>>m; 
    for(int i=1;i<=n;i++) { 
        for(int j=1;j<=m;j++) { 
            cin>>map[i][j]; 
        } 
    } 
    DFS(n,1,1); 
    cout<<dis; 
} 
 
