#include<iostream>
#include<memory.h>
#include<queue>
using namespace std;
struct A {
	int vis[20];
	int now,level,bound,cnt;
	bool operator<(const A &a) const {
		return bound > a.bound;
	}
};
priority_queue<A> qu;
int n;
int map[20][20];
A a;
int main() {
	cin>>n;
	int i,j,k;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			cin>>map[i][j];
		}
	}
	a.level = 1;
	a.now = 1;
	a.vis[1]=1;
	for(i=1;i<=n;i++) {
		int mn=99999999;
		for(j=1;j<=n;j++) {
			if(mn > map[i][j] && map[i][j] != 0) mn = map[i][j];
		}
		a.bound+=mn;
	}
	qu.push(a);
	int ans=999999999;
	while(!qu.empty()) {
		A f = qu.top();
		qu.pop();
		int sum=0;
		if(f.bound >= ans) break;
		for(i=1;i<=n;i++) {
			if(f.vis[i] == 1 || map[f.now][i] == 0) continue;
			A c = f;
			c.now = i;
			c.cnt = f.cnt + map[f.now][i];
			if(c.level+1 == n) {
				c.cnt += map[i][1];
				if(c.cnt < ans) {
					ans = c.cnt;
				}
			} else {
				c.cnt = f.cnt+map[f.now][i];
				c.vis[i]=1;
				c.now = i;
				c.level++;
				sum=c.cnt;
				for(j=1;j<=n;j++) {
					int mn=99999999;
					for(k=1;k<=n;k++) {
						if(c.vis[j] && j != c.now) break;
						if(j == c.now) {
							if(mn > map[j][k] && j != k && !c.vis[k] && map[j][k] != 0) {
								mn = map[j][k];
							}
						} else {
							if(mn > map[j][k] && j != k && (!c.vis[k] || k==1) && map[j][k] != 0) {
								mn = map[j][k];	
							}
						}
					}
					if(!c.vis[j] || j == c.now) sum+=mn;
				} // end j
				c.bound = sum;
				qu.push(c);
			} //end else
		} //end i
	}
	cout<<ans;
}
