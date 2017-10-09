#include<iostream>
#include<queue>
using namespace std;
struct A {
	int y,x;
	int breakpoint;
	bool operator<(const A &a) const {
		return breakpoint > a.breakpoint;
	}
};
char map[100][100];
int vis[100][100];
int br[100][100];
int n;
priority_queue<A> qu;
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			cin>>map[i][j];
			br[i][j]=999999;
		}
	}
	A a;
	a.y = 1;
	a.x = 1;
	a.breakpoint = 0;
	qu.push(a);
	br[1][1]=0;
	int breaks=0;
	while(!qu.empty()) {
		A f = qu.top();
		qu.pop();
		if(f.y == n && f.x == n) {
			breaks = f.breakpoint;
			break;
		}
		//4방향 검사.
		if(f.y-1 >= 1) {
			int p = f.breakpoint+(1-(map[f.y-1][f.x]-48));
			if(p < br[f.y-1][f.x]) {
				br[f.y-1][f.x] = p;
				a.y = f.y-1;
				a.x = f.x;
				a.breakpoint = p;
				qu.push(a);
			}
		}
		if(f.x-1 >= 1) {
			int p = f.breakpoint+(1-(map[f.y][f.x-1]-48));
			if(p < br[f.y][f.x-1]) {
				br[f.y][f.x-1] = p;
				a.y = f.y;
				a.x = f.x-1;
				a.breakpoint = p;
				qu.push(a);
			}
		}
		if(f.y+1 <= n) {
			int p = f.breakpoint+(1-(map[f.y+1][f.x]-48));
			if(p < br[f.y+1][f.x]) {
				br[f.y+1][f.x] = p;
				a.y = f.y+1;
				a.x = f.x;
				a.breakpoint = p;
				qu.push(a);	
			}
		}
		if(f.x+1 <= n) {
			int p = f.breakpoint+(1-(map[f.y][f.x+1]-48));
			if(p < br[f.y][f.x+1]) {
				br[f.y][f.x+1] = p;
				a.y = f.y;
				a.x = f.x+1;
				a.breakpoint = p;
				qu.push(a);	
			}
		}
	}
	cout<<breaks;
}