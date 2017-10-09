#include<iostream> 
using namespace std; 
int n,l; 
int mx=0; 
int map[122][122]={0}; 
int vis[122][122]={0}; 
// 1 = 왼쪽, 2 = 오른쪽 , 3 = 상, 4 = 하 
void DFS(int i,int j,int t,int co) { 
    if(i < 0 || j < 0 || i > n || j > n) return; 
    vis[i][j]=1; 
    if(co > mx) { 
        mx = co; 
    } 
    if(t == 1) { 
        if(map[i][j-1] == 1) { 
            if(vis[i-1][j]==0&&map[i-1][j]==0)DFS(i-1,j,3,co+1); 
            if(vis[i+1][j]==0&&map[i+1][j]==0)DFS(i+1,j,4,co+1); 
        } else { 
            if(vis[i][j-1]==0&&map[i][j-1]==0) DFS(i,j-1,t,co+1); 
        } 
    } else if(t == 2) { 
        if(map[i][j+1] == 1) { 
            if(vis[i-1][j]==0&&map[i-1][j]==0)DFS(i-1,j,3,co+1); 
            if(vis[i+1][j]==0&&map[i+1][j]==0)DFS(i+1,j,4,co+1); 
        } else { 
            if(vis[i][j+1]==0&&map[i][j+1]==0) DFS(i,j+1,t,co+1); 
        } 
    } else if(t == 3) { 
        if(map[i-1][j] == 1) { 
            if(vis[i][j-1]==0&&map[i][j-1]==0) DFS(i,j-1,1,co+1); 
            if(vis[i][j+1]==0&&map[i][j+1]==0) DFS(i,j+1,2,co+1); 
        } else { 
            if(vis[i-1][j]==0&&map[i-1][j]==0) DFS(i-1,j,t,co+1); 
        } 
    } else if(t == 4) { 
        if(map[i+1][j] == 1) { 
            if(vis[i][j-1]==0&&map[i][j-1]==0) DFS(i,j-1,1,co+1); 
            if(vis[i][j+1]==0&&map[i][j+1]==0) DFS(i,j+1,2,co+1); 
        } else {  
            if(vis[i+1][j]==0&&map[i+1][j]==0) DFS(i+1,j,t,co+1); 
        } 
    } 
    vis[i][j]=0; 
} 
int main() { 
    cin>>n>>l; 
    for(int i=0;i<l;i++) { //장애물 셋팅. 
        char c; 
        int t; 
        cin>>c>>t; 
        map[t][c-65+1] = 1; 
    } 
  
    for(int i=0;i<=n+1;i++) { // 외벽 셋팅. 
        map[i][0]=1; 
        map[i][n+1]=1; 
        for(int j=0;j<=n+1;j++) { 
            map[0][j]=1; 
            map[n+1][j]=1; 
        } 
    } 
    vis[1][1]=1; 
    if(vis[2][1] == 0 && map[2][1] == 0) DFS(2,1,4,2); 
    if(vis[1][2] ==0 && map[1][2] == 0) DFS(1,2,2,2); 
    cout<<mx; 
} 
 
