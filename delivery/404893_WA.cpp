#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<queue>
using namespace std;
int n,m;
char c[1000][1000];
int vis[1000][1000];
int dis[1000][1000];
struct B {
	int dis1,dis2;
};
B dp[1000][1000];
struct A {
	int y,x,dis;
};
A houses[1000];
A s1;
int ind=1;
bool cmp(A a,A b) {
	return dis[a.y][a.x] < dis[b.y][b.x];
}
void BFS() {
	queue<A> qu;
	qu.push(s1);
	while(!qu.empty()) {
		int y = qu.front().y;
		int x = qu.front().x;
		int diss = qu.front().dis;
		if(dis[y][x] == -1 || dis[y][x] > diss) {
			dis[y][x]=diss;
		}
		A a;
		vis[y][x]=1;
		if(c[y+1][x] != '#' && y+1 <= n && vis[y+1][x] == 0) {
			vis[y+1][x]=1;
			a.y = y+1;
			a.x = x;
			a.dis = diss+1;
			qu.push(a);
		}
		if(c[y-1][x] != '#' && y-1 >= 1 && vis[y-1][x] == 0) {
			vis[y-1][x]=1;
			a.y = y-1;
			a.x = x;
			a.dis = diss+1;
			qu.push(a);
		}
		if(c[y][x+1] != '#' && x+1 <= m && vis[y][x+1] == 0) {
			vis[y][x+1]=1;
			a.y = y;
			a.x = x+1;
			a.dis = diss+1;
			qu.push(a);
        }
        if(c[y][x-1] != '#' && x-1 >= 1 && vis[y][x-1] == 0) {
			vis[y][x-1]=1;
			a.y = y;
			a.x = x-1;
			a.dis = diss+1;
			qu.push(a);
		}
		qu.pop();
	}
}
int main() {
	cin>>n>>m;
	int i,j;
	bool t=false;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			cin>>c[i][j];
			dis[i][j]=-1;
			if(c[i][j] == 'S') {
				s1.y = i;
				s1.x = j;
			} else if(c[i][j] == 'H') {
				houses[ind].y=i;
				houses[ind++].x=j;
			}
		}
	}
	BFS();
	houses[0].x=s1.x;
	houses[0].y=s1.y;
	dis[0][0]=99999999;
	for(i=0;i<=n;i++) for(j=0;j<=n;j++) {dp[i][j].dis1=99999999;dp[i][j].dis2=99999999;}
	sort(houses+1,houses+ind,cmp);
	dp[0][1].dis2=dis[houses[1].y][houses[1].x];
	dp[0][1].dis1=0;
	ind--;
	for(i=2;i<=ind;i++) {
		for(j=0;j<i;j++) {
			if(i!=2&&i-1==j) continue;
			if(max(dp[j][i-1].dis2,dp[j][i-1].dis1+dis[houses[j].y][houses[j].x]+dis[houses[i].y][houses[i].x]) < max(dp[i-1][i].dis1,dp[i-1][i].dis2)) {
				dp[i-1][i].dis1=dp[j][i-1].dis2;
				dp[i-1][i].dis2=dp[j][i-1].dis1+dis[houses[j].y][houses[j].x]+dis[houses[i].y][houses[i].x];
			}
			if(max(dp[j][i-1].dis1,dp[j][i-1].dis2+dis[houses[i-1].y][houses[i-1].x]+dis[houses[i].y][houses[i].x]) < max(dp[j][i].dis1,dp[j][i].dis2)) {
				dp[j][i].dis1=dp[j][i-1].dis1;
				dp[j][i].dis2=dp[j][i-1].dis2+dis[houses[i-1].y][houses[i-1].x]+dis[houses[i].y][houses[i].x];
			}
		}
	}
	int mn=99999999;
	for(i=0;i<ind;i++) {
		if(mn > max(dp[i][ind].dis1,dp[i][ind].dis2)) mn = max(dp[i][ind].dis1,dp[i][ind].dis2);
	}
	cout<<mn;
}