#include<iostream>
#include<queue>
using namespace std;
struct pos {
    int i,j;
};
int m,n; //열, 행
char map[1001][81]={NULL};//맵
int c[1001][81]={0};//중 ㅋ 복 ㅋ 방 ㅋ 지 ㅋ 용
int y=0;
int mx=0;
queue<pos> qu;
 
void BFS(int i,int j) {
    if(i < 1 || j < 1) return;
    if(i > n || j > m) return;
    int cnt=0;
    pos pos;
    pos.i = i;
    pos.j = j;
    qu.push(pos);
    c[i][j]=y;
    while(!qu.empty()) {
        int fi=qu.front().i;
        int fj =qu.front().j;
        if(map[fi+1][fj] == '*' && c[fi+1][fj] == 0) {
            pos.i = fi+1;
            pos.j = fj;
            qu.push(pos);
            c[fi+1][fj] = y;
        }
        if(map[fi-1][fj] == '*' && c[fi-1][fj] == 0) {
            pos.i = fi-1;
            pos.j = fj;
            qu.push(pos);
            c[fi-1][fj] = y;
        }
        if(map[fi][fj+1] == '*' && c[fi][fj+1] == 0) {
            pos.i = fi;
            pos.j = fj+1;
            qu.push(pos);
            c[fi][fj+1] = y;
        }
        if(map[fi][fj-1] == '*' && c[fi][fj-1] == 0) {
            pos.i = fi;
            pos.j = fj-1;
            qu.push(pos);
            c[fi][fj-1] = y;
        }
     
        if(!qu.empty()) qu.pop();
    }
 
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(map[i][j] == '*' && c[i][j] == y) {
                cnt++;
            }
        }
    }
    if(cnt > mx) mx = cnt;
}
int main() {
    cin>>m>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>map[i][j];
 
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(map[i][j] == '*' && c[i][j] == 0) {
                y++;
                BFS(i,j);
            }
        }
    }
 
    cout<<mx;
}