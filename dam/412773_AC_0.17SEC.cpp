#include<iostream>
#include<queue>
using namespace std;
int n;
int map[1000][1000];
int vis[1000][1000];
struct A {
	int x,y,level;
};
int sy,sx;
int T;
queue<A> qu;
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			scanf("%d",&map[i][j]);
		}
	}
	scanf("%d%d",&sx,&sy);
	scanf("%d",&T);
	A a;
	a.y = sy;
	a.x = sx;
	a.level = 0;
	qu.push(a);
	int cnt=0;
	while(!qu.empty()) {
		int x = qu.front().x;
		int y = qu.front().y;
		int level = qu.front().level;
		vis[y][x]=1;
		a.level = level+1;
		if(level == T) {
			cnt++;
		}
		if(map[y+1][x] == 0 && vis[y+1][x]==0 && y+1 <= n) {
			vis[y+1][x]=1;
			a.y = y+1;
			a.x = x;
			qu.push(a);
		}
		if(map[y-1][x] == 0 && vis[y-1][x] == 0 && y-1 >= 1) {
			vis[y-1][x]=1;
			a.y = y-1;
			a.x = x;
			qu.push(a);
		}
		if(map[y][x+1] == 0 && vis[y][x+1] == 0 && x+1 <= n) {
			vis[y][x+1]=1;
			a.y = y;
			a.x = x+1;
			qu.push(a);
		}
		if(map[y][x-1] == 0 && vis[y][x-1] == 0 && x-1 >= 1) {
			vis[y][x-1]=1;
			a.y = y;
			a.x = x-1;
			qu.push(a);
		}
		qu.pop();
	}
	if(cnt ==0) printf("OH, MY GOD");
	else printf("%d",cnt);
}