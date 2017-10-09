#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,k;
struct A {
	int ind,revamp,dis;
	bool operator<(const A &a) const {
		return dis > a.dis;
	}
};
int dis[30][100000];
int vis[30][100000];
vector<A> ve[100000];
A aa;
priority_queue<A> qu;
int main() {
	int i,j;
	scanf("%d%d%d",&n,&m,&k);
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c) != -1) {
		aa.ind = b;
		aa.dis = c;
		ve[a].push_back(aa);
		aa.ind = a;
		ve[b].push_back(aa);
	}
	for(i=0;i<30;i++) for(j=2;j<=m;j++) dis[i][j]=-1;
	aa.ind = 1;
	aa.dis = 0;
	qu.push(aa);
	vis[1][1]=1;
	int cnt=0;
	while(!qu.empty()) {
		A aaa = qu.top();
		qu.pop();
		if(cnt == m) break;
		if(vis[aaa.revamp][aaa.ind]==1) {
			continue;
		} else {
			vis[aaa.revamp][aaa.ind]=1;
			cnt++;
		}
		for(i=0;i<ve[aaa.ind].size();i++) {
			if(dis[aaa.revamp][ve[aaa.ind][i].ind] > ve[aaa.ind][i].dis+aaa.dis || dis[aaa.revamp][ve[aaa.ind][i].ind] == -1) {
				aa.ind = ve[aaa.ind][i].ind;
				aa.dis = ve[aaa.ind][i].dis+aaa.dis;
				dis[aaa.revamp][ve[aaa.ind][i].ind]=aa.dis;
				aa.revamp = aaa.revamp;
				qu.push(aa);
			}
			if((dis[aaa.revamp+1][ve[aaa.ind][i].ind] > aaa.dis || dis[aaa.revamp+1][ve[aa.ind][i].ind] == -1) && aaa.revamp+1 <= k) {
				aa.dis = aaa.dis;
				dis[aaa.revamp+1][ve[aaa.ind][i].ind]=aa.dis;
				aa.ind = ve[aaa.ind][i].ind;
				aa.revamp = aaa.revamp+1;
				qu.push(aa);
			}
		}
	}
	int mn=99999999;
	for(i=0;i<=k;i++) {
		if(dis[i][n] < mn) mn = dis[i][n];
	}
	printf("%d",mn);
}