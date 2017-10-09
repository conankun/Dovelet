#include<iostream> 
#include<algorithm> 
using namespace std; 
int n; 
int map[27][27]={0}; 
int vis[27][27]={0}; 
int map2[1000]={0}; 
int cnt=0; 
void DFS(int i,int j) { 
    if(i<=0||j<=0||i>n||j>n) return; 
    vis[i][j]=cnt; 
    map2[cnt]++; 
    if(map[i+1][j]==1 && vis[i+1][j] == 0) { 
        vis[i+1][j] = cnt; 
        DFS(i+1,j); 
    } 
    if(map[i-1][j]==1 && vis[i-1][j] == 0) { 
        vis[i-1][j] = cnt; 
        DFS(i-1,j); 
    } 
    if(map[i][j+1]==1 && vis[i][j+1] == 0) { 
        vis[i][j+1]=cnt; 
        DFS(i,j+1); 
    }    
    if(map[i][j-1]==1 && vis[i][j-1] == 0) { 
        vis[i][j-1]=cnt; 
        DFS(i,j-1); 
    } 
} 
int main() { 
    cin>>n; 
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>map[i][j]; 
    for(int i=1;i<=n;i++) { 
        for(int j=1;j<=n;j++) { 
            if(vis[i][j] == 0 && map[i][j] == 1) { 
                cnt++; 
                DFS(i,j); 
            } 
        } 
    } 
  
    sort(map2+1,map2+cnt+1); 
    cout<<cnt; 
    for(int i=1;i<=cnt;i++) { 
    cout<<endl<<map2[i]; 
    } 
} 
 
