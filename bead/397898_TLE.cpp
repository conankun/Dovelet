#include<iostream>
#include<stdlib.h>
using namespace std;
int n,m;
int map[101][101];
int small[101][101];
int big[101][101];
int path[10000];
int ind;
int cnt;
int vis[101];
void DFS(int bead) {
	int i;
	for(i=0;i<ind;i++) {
		big[bead][path[i]]=1;
		small[path[i]][bead]=1;
	}
	path[ind++]=bead;
	for(i=1;i<=n;i++) {
		if(map[bead][i] == 1) {
			DFS(i);
		}
	}
	path[ind--]=0;
}
int main() {
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=m;i++) {
		int a,b;
		cin>>a>>b;
		map[a][b]=1;
	}
	for(i=1;i<=n;i++) {
		DFS(i);
	}
	for(i=1;i<=n;i++) {
		int s=0,b=0;
		for(j=1;j<=n;j++) {
			s+=small[i][j];
			b+=big[i][j];
		}
		//n-(s+b)-1
		int g = n-(s+b)-1;
		bool t=false;
		for(j=0;j<=g;j++) {//s
			int tt = g-j;//b
			if(s+j == b+tt || (abs((s+j)-(b+tt)) <= 1 && n%2 == 1)) {
				t=true;
				break;
			}
		}
		if(!t) {
			cnt++;
		}
	}
	cout<<cnt;
}