#include<iostream>
#include<queue>
using namespace std;
char map[100][100];
struct A {
	int x,y,dis;
};
int L,W;
int main() {
	cin>>L>>W;
	int i,j;
	for(i=1;i<=L;i++) for(j=1;j<=W;j++) cin>>map[i][j];
	int mx=0;
	for(i=1;i<=L;i++) {
		for(j=1;j<=W;j++) {
			if(map[i][j]!='L') continue;
			int vis[100][100]={0};
			int mxdis=0;
			queue<A> qu;
			A a;
			a.x=i;a.y=j;a.dis=0;
			qu.push(a);
			while(!qu.empty()) {
				int x=qu.front().x;
				int y=qu.front().y;
				int dis=qu.front().dis;
				if(dis > mxdis) mxdis=dis;
				qu.pop();
				if(map[x+1][y]=='L' && vis[x+1][y]==0) {
					vis[x+1][y]=1;
					a.x=x+1;a.y=y;a.dis=dis+1;
					qu.push(a);
				}
				if(map[x-1][y]=='L' && vis[x-1][y]==0) {
					vis[x-1][y]=1;
					a.x=x-1;a.y=y;a.dis=dis+1;
					qu.push(a);
				}
				if(map[x][y+1]=='L' && vis[x][y+1]==0) {
					vis[x][y+1]=1;
					a.x=x;a.y=y+1;a.dis=dis+1;
					qu.push(a);
				}
				if(map[x][y-1]=='L' && vis[x][y-1]==0) {
					vis[x][y-1]=1;
					a.x=x;a.y=y-1;a.dis=dis+1;
					qu.push(a);
				}
			}
			if(mxdis > mx) mx=mxdis;
		}
	}
	cout<<mx;
}