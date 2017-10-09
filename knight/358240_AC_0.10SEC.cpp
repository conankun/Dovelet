#include<iostream> 
#include<queue> 
using namespace std; 
#define n 1000 
#define m 1000 
struct A { 
    int x,y; 
    int cnt; 
}; 
queue<A> qu; 
int vis[10001][10001]={0}; 
int main() { 
    int r,c,s,k; 
    cin>>r>>c>>s>>k; 
    A a; 
    a.x = c; 
    a.y = r; 
    a.cnt=0; 
    qu.push(a); 
    while(!qu.empty()) { 
        int x=qu.front().x; 
        int y=qu.front().y; 
        if(x == k && y == s) break; 
        vis[x][y]=1; 
        if(vis[x+1][y+2] != 1 && (x+1<=m && y+2<=n)) { 
            a.x = x+1; 
            a.y = y+2; 
            a.cnt = qu.front().cnt + 1; 
            qu.push(a); 
            vis[x+1][y+2]=1; 
        } 
        if(y-2 > 0) 
        if(vis[x+1][y-2] != 1 && (x+1<=m && y-2>=1)) { 
            a.x = x+1; 
            a.y = y-2; 
            a.cnt = qu.front().cnt + 1; 
            qu.push(a); 
            vis[x+1][y-2]=1; 
        } 
        if(vis[x+2][y+1] != 1 && (x+2<=m && y+1<=n)) { 
            a.x = x+2; 
            a.y = y+1; 
            a.cnt = qu.front().cnt + 1; 
            qu.push(a); 
            vis[x+2][y+1]=1; 
        } 
        if(y-1 > 0) 
        if(vis[x+2][y-1] != 1 && (x+2<=m && y-1>=1)) { 
            a.x = x+2; 
            a.y = y-1; 
            a.cnt = qu.front().cnt + 1; 
            qu.push(a); 
            vis[x+2][y-1]=1; 
        } 
        // 
        if(x-1 > 0) 
        if(vis[x-1][y+2] != 1 && (x-1>=1 && y+2<=n)) { 
            a.x = x-1; 
            a.y = y+2; 
  
            a.cnt = qu.front().cnt + 1; 
            qu.push(a); 
            vis[x-1][y+2]=1; 
        } 
        if(x-1 > 0 && y-2 > 0) 
        if(vis[x-1][y-2] != 1 && (x-1>=1 && y-2>=1)) { 
            a.x = x-1; 
            a.y = y-2; 
            a.cnt = qu.front().cnt + 1; 
            qu.push(a); 
            vis[x-1][y-2]=1; 
        } 
        if(x-2 > 0) 
        if(vis[x-2][y+1] != 1 && (x-2>=1 && y+1<=n)) { 
            a.x = x-2; 
            a.y = y+1; 
            a.cnt = qu.front().cnt + 1; 
            qu.push(a); 
            vis[x-2][y+1]=1; 
        } 
        if(x-2 > 0 && y-1 > 0) 
        if(vis[x-2][y-1] != 1 && (x-2>=1 && y-1>=1)) { 
            a.x = x-2; 
            a.y = y-1; 
            a.cnt = qu.front().cnt + 1; 
            qu.push(a); 
            vis[x-2][y-1]=1; 
        } 
        qu.pop(); 
    } 
    cout<<qu.front().cnt; 
} 
 
