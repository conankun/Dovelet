#include<iostream> 
using namespace std; 
int a,b; 
char c[111][111]={NULL,}; 
int d[111][111]={0,}; 
int cnt=0; 
void DFS(int i,int j) { 
    if(i<1 || j<1) return; 
    if(i>a || j > b) return; 
    if(c[i][j] == '.') return; 
    if(c[i][j] == 'W' && d[i][j] == 0) d[i][j] = cnt; 
  
    if(c[i+1][j] == 'W' && d[i+1][j] == 0) DFS(i+1,j); 
    if(c[i-1][j] == 'W' && d[i-1][j] == 0) DFS(i-1,j); 
    if(c[i][j-1] == 'W' && d[i][j-1] == 0) DFS(i,j-1); 
    if(c[i][j+1] == 'W' && d[i][j+1] == 0) DFS(i,j+1); 
    if(c[i+1][j+1] == 'W' && d[i+1][j+1] == 0) DFS(i+1,j+1); 
    if(c[i+1][j-1] == 'W' && d[i+1][j-1] == 0) DFS(i+1,j-1); 
    if(c[i-1][j+1] == 'W' && d[i-1][j+1] == 0) DFS(i-1,j+1); 
    if(c[i-1][j-1] == 'W' && d[i-1][j-1] == 0) DFS(i-1,j-1); 
  
    return; 
} 
  
int main() { 
    cin>>a>>b; 
    for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) cin>>c[i][j]; 
  
    for(int i=1;i<=a;i++) { 
        for(int j=1;j<=b;j++) { 
            if(c[i][j] == 'W' && d[i][j] == 0) { 
            cnt++; 
            DFS(i,j); 
            } else continue; 
        } 
    } 
    cout<<cnt; 
} 
 
