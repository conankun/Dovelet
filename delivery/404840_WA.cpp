#include<iostream>
#include<queue>
using namespace std;
int n,m;
char c[1000][1000];
int dis1[1000][1000];
int vis1[1000][1000];
int dis2[1000][1000];
int vis2[1000][1000];
struct A {
	int y,x,dis;
};
queue<A> qu1;
queue<A> qu2;
A s1;
A s2;
int main() {
	cin>>n>>m;
	int i,j;
	bool t=false;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			cin>>c[i][j];
			dis1[i][j]=-1;
			dis2[i][j]=-1;
			if(!t && c[i][j] == 'S') {
				s1.y = i;
				s1.x = j;
				t=true;
			} else if(c[i][j] == 'S') {
				s2.y = i;
				s2.x = j;
			}
		}
	}
	qu1.push(s1);
	while(!qu1.empty()) {
		int y = qu1.front().y;
		int x = qu1.front().x;
		int dis = qu1.front().dis;
		if(dis1[y][x] == -1 || dis1[y][x] > dis) {
			dis1[y][x]=dis;
		}
		A a;
		vis1[y][x]=1;
		if(c[y+1][x] != '#' && y+1 <= n && vis1[y+1][x] == 0) {
			vis1[y+1][x]=1;
			a.y = y+1;
			a.x = x;
			a.dis = dis+1;
			qu1.push(a);
		}
		if(c[y-1][x] != '#' && y-1 >= 1 && vis1[y-1][x] == 0) {
			vis1[y-1][x]=1;
			a.y = y-1;
			a.x = x;
			a.dis = dis+1;
			qu1.push(a);
		}
		if(c[y][x+1] != '#' && x+1 <= m && vis1[y][x+1] == 0) {
			vis1[y][x+1]=1;
			a.y = y;
			a.x = x+1;
			a.dis = dis+1;
			qu1.push(a);
		}
		if(c[y][x-1] != '#' && x-1 >= 1 && vis1[y][x-1] == 0) {
			vis1[y][x-1]=1;
			a.y = y;
			a.x = x-1;
			a.dis = dis+1;
			qu1.push(a);
		}
		qu1.pop();
	}
	int sum=0;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			if(c[i][j] == 'H') {
				if(sum<dis1[i][j]) sum=dis1[i][j];
			}
		}
	}
	cout<<sum;
}