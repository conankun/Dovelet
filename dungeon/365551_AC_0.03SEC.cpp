#include<iostream>
#include<queue>
using namespace std;
char map[32][32][32];
int vis[32][32][32];

struct A {
	int i,j,k;
	int dis;
};
queue<A> qu;
int main() {
	int l,r,c;
	int i,j,k;
	int s1,s2,s3;
	int e1,e2,e3;
	scanf("%d%d%d",&l,&r,&c);
	scanf("\n");
	for(i=1;i<=l;i++) {
		for(j=1;j<=r;j++) {
			for(k=1;k<=c;k++) {
				char c;
				scanf("%c",&c);
				if(c == 'S') {
					s1 = i;
					s2 = j;
					s3 = k;
				} else if(c == 'E') {
					e1 = i;
					e2 = j;
					e3 = k;
				}
				map[i][j][k]=c;
			}
			scanf("\n");
		}
	}
	A a;
	a.dis = 0;
	a.i = s1;
	a.j = s2;
	a.k = s3;
	qu.push(a);
	while(!qu.empty()) {
		i=qu.front().i;
		j=qu.front().j;
		k=qu.front().k;
		int dis = qu.front().dis;
		vis[i][j][k]=dis;
		if(vis[i+1][j][k] == 0 && i+1 <= l && map[i+1][j][k] != '#') {
			a.i = i+1;
			a.j = j;
			a.k = k;
			a.dis = dis+1;
			vis[i+1][j][k]=dis+1;
			qu.push(a);
		} 
		if(vis[i-1][j][k] == 0 && i-1 >= 1 && map[i-1][j][k] != '#') {
			a.i = i-1;
			a.j = j;
			a.k = k;
			a.dis = dis+1;
			vis[i-1][j][k]=dis+1;
			qu.push(a);
		}
		if(vis[i][j+1][k] == 0 && j+1 <= r && map[i][j+1][k] != '#') {
			a.i = i;
			a.j = j+1;
			a.k = k;
			a.dis = dis+1;
			vis[i][j+1][k]=dis+1;
			qu.push(a);
		}
		if(vis[i][j-1][k] == 0 && j-1 >= 1 && map[i][j-1][k] != '#') {
			a.i = i;
			a.j = j-1;
			a.k = k;
			a.dis = dis+1;
			vis[i][j-1][k]=dis+1;
			qu.push(a);
		}
		if(vis[i][j][k+1] == 0 && k+1 <= c && map[i][j][k+1] != '#') {
			a.i = i;
			a.j = j;
			a.k = k+1;
			a.dis = dis+1;
			vis[i][j][k+1]=dis+1;
			qu.push(a);
		}
		if(vis[i][j][k-1] == 0 && k-1 >= 1 && map[i][j][k-1] != '#') {
			a.i = i;
			a.j = j;
			a.k = k-1;
			a.dis = dis+1;
			vis[i][j][k-1]=dis+1;
			qu.push(a);
		}
		qu.pop();
	}
	if(vis[e1][e2][e3] == 0) {
		cout<<"Trapped!";
	} else {
		cout<<"Escaped in "<<vis[e1][e2][e3]<<" minute(s).";
	}
}