#include<iostream> 
#include<queue> 
using namespace std; 
char map[1001][1001]={0}; 
int vis1[1001][1001]={0}; 
int vis2[1001][1001]={0}; 
struct A { 
    int y,x; 
    int level; 
}; 
int main() { 
    int c,r; 
    cin>>r>>c; // 가로,세로(바뀜 ㅋ) 
    for(int i=0;i<c;i++) { 
        cin>>map[i]; 
    } 
    int px,py; 
    for(int i=0;i<c;i++) { 
        bool t=false; 
        for(int j=0;j<r;j++) { 
            if(map[i][j] == '.') { 
                px = j; 
                py = i; 
                t=true; 
                break; 
            } 
        } 
        if(t) break; 
    } 
  
    //임시로 잡은 점을 기점으로 BFS돌려서 가장 먼 곳을 찾는다. 
    queue<A> qu1; 
    A a; 
    a.y = py,a.x = px; 
    a.level = 0; 
    qu1.push(a); 
    int rx=px,ry = py,rl=0; 
    while(!qu1.empty()) { 
        int y=qu1.front().y; 
        int x=qu1.front().x; 
        int level=qu1.front().level; 
        vis1[y][x]=level; 
        if(level > rl) { 
            rl=level; 
            rx = x; 
            ry = y; 
        } 
        if(map[y+1][x] == '.' && (vis1[y+1][x] > level+1 || vis1[y+1][x] == 0)) { 
            vis1[y+1][x]=level+1; 
            a.y = y+1; 
            a.x = x; 
            a.level = level+1; 
            qu1.push(a); 
        } 
        if(map[y-1][x] == '.'&& (vis1[y-1][x] > level+1 || vis1[y-1][x] == 0)) { 
            vis1[y-1][x]=level+1; 
            a.y = y-1; 
            a.x = x; 
            a.level = level+1; 
            qu1.push(a); 
        } 
        if(map[y][x+1] == '.' && (vis1[y][x+1] > level+1 || vis1[y][x+1] == 0)) { 
            vis1[y][x+1]=level+1; 
            a.y = y; 
            a.x = x+1; 
            a.level = level+1; 
            qu1.push(a); 
        } 
        if(map[y][x-1] == '.' && (vis1[y][x-1] > level+1 || vis1[y][x-1] == 0)) { 
            vis1[y][x-1]=level+1; 
            a.y = y; 
            a.x = x-1; 
            a.level = level+1; 
            qu1.push(a); 
        } 
        qu1.pop(); 
    } 
    queue<A> qu2; 
    a.y = ry,a.x = rx; 
    a.level = 0; 
    qu2.push(a); 
    int ax=rx,ay = ry,al=0; 
    while(!qu2.empty()) { 
        int y=qu2.front().y; 
        int x=qu2.front().x; 
        int level=qu2.front().level; 
        vis2[y][x]=level; 
        if(level > al) { 
            al=level; 
            ax = x; 
            ay = y; 
        } 
        if(map[y+1][x] == '.' && (vis2[y+1][x] > level+1 || vis2[y+1][x] == 0)) { 
            vis2[y+1][x]=level+1; 
            a.y = y+1; 
            a.x = x; 
            a.level = level+1; 
            qu2.push(a); 
        } 
        if(map[y-1][x] == '.'&& (vis2[y-1][x] > level+1 || vis2[y-1][x] == 0)) { 
            vis2[y-1][x]=level+1; 
            a.y = y-1; 
            a.x = x; 
            a.level = level+1; 
            qu2.push(a); 
        } 
        if(map[y][x+1] == '.' && (vis2[y][x+1] > level+1 || vis2[y][x+1] == 0)) { 
            vis2[y][x+1]=level+1; 
            a.y = y; 
            a.x = x+1; 
            a.level = level+1; 
            qu2.push(a); 
        } 
        if(map[y][x-1] == '.' && (vis2[y][x-1] > level+1 || vis2[y][x-1] == 0)) { 
            vis2[y][x-1]=level+1; 
            a.y = y; 
            a.x = x-1; 
            a.level = level+1; 
            qu2.push(a); 
        } 
        qu2.pop(); 
    } 
    cout<<"Maximum rope length is "<<al<<"."; 
} 
 
