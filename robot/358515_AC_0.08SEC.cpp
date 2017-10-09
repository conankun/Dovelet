#include<iostream> 
using namespace std; 
int r,c,s; 
char map[100][100]={0}; 
int vis[100][100]={0}; 
void bt(int i,int j,int level) { 
    if(vis[i][j] != 0 || (i == 1 && j == s && level !=0)) { //루프발생. 
        cout<<vis[i][j]<<" step(s) before a loop of "<<level-vis[i][j]<<" step(s)"; 
        return; 
    } 
    if(i == 0 || i > r || j == 0 || j > c) { //탈출성공 
        cout<<level<<" step(s) to exit"; 
        return; 
    } 
    vis[i][j]=level; 
    switch(map[i][j]) { 
    case 'N': { 
                bt(i-1,j,level+1); 
                break; 
              } 
    case 'S': { 
                bt(i+1,j,level+1); 
                break; 
              } 
    case 'W': { 
                bt(i,j-1,level+1); 
                break; 
              } 
    case 'E': { 
                bt(i,j+1,level+1); 
                break; 
              } 
    } 
} 
int main() { 
    cin>>r>>c>>s; 
    for(int i=1;i<=r;i++) { 
        for(int j=1;j<=c;j++) { 
            cin>>map[i][j]; 
        } 
    } 
    bt(1,s,0); 
} 
 
