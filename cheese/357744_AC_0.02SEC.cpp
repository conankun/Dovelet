#include<iostream> 
#include<queue> 
using namespace std; 
int map[1000][1000]={0}; 
int vis[1000][1000]={0}; 
int n,m; 
struct A { int x,y; }; 
void BFS() { 
    queue<A> qu; 
    A a; 
    a.x = 1; 
    a.y = 1; 
    qu.push(a); 
    while(!qu.empty()) { 
        int x = qu.front().x; 
        int y = qu.front().y; 
        map[y][x] = 2; 
        if(map[y+1][x] == 0 && vis[y+1][x] == 0) { 
            vis[y+1][x] = 1; 
            a.x = x; 
            a.y = y+1; 
            qu.push(a); 
        } 
        if(map[y-1][x] == 0 && vis[y-1][x] == 0) { 
            vis[y-1][x] = 1; 
            a.x = x; 
            a.y = y-1; 
            qu.push(a); 
        } 
        if(map[y][x+1] == 0 && vis[y][x+1] == 0) { 
            vis[y][x+1]=1; 
            a.x = x+1; 
            a.y = y; 
            qu.push(a); 
        } 
        if(map[y][x-1] == 0 && vis[y][x-1] == 0) { 
            vis[y][x-1]=1; 
            a.x = x-1; 
            a.y = y; 
            qu.push(a); 
        } 
        qu.pop(); 
    } 
} 
bool check() { 
    bool b = true; 
    for(int i=1;i<=n;i++) { 
        for(int j=1;j<=m;j++) { 
            vis[i][j]=0; 
            if(map[i][j] == 2) map[i][j]=0; 
            if(map[i][j] != 0) b = false; 
        } 
    } 
    return b; 
} 
int main() { 
    cin>>n>>m; 
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>map[i][j]; 
    for(int i=0;i<=m+1;i++) { 
        map[0][i] = 3; 
        map[n+1][i] = 3; 
    } 
    for(int i=0;i<=n+1;i++) { 
        map[i][0] = 3; 
        map[i][m+1] =  3; 
    } 
    for(int i=1;i<=1000;i++) { 
        BFS(); 
        for(int y=1;y<=n;y++) { 
            for(int x=1;x<=m;x++) { 
                if(map[y][x] == 1) { 
                    int cnt=0; 
                    if(map[y+1][x] == 2) cnt++; 
                    if(map[y-1][x] == 2) cnt++; 
                    if(map[y][x+1] == 2) cnt++; 
                    if(map[y][x-1] == 2) cnt++; 
                    if(cnt >=2) { 
                        map[y][x] = 0; 
                    } 
                } 
            } 
        } 
        if(check()) { 
            cout<<i; 
            break; 
        } 
    } 
} 
 
