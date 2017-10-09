#include<iostream>
using namespace std;
int n,m;
int map[2011][2011];
int vis[2011];
bool t=false;
void DFS(int bug) {
	if(vis[bug] == 1) {
		t=true;
		return;
	} else {
		vis[bug]=1;
		int i;
		for(i=1;i<=n;i++) {
			if(map[bug][i] == 1)  {
				DFS(i);
			}
		}
	}
}
int main() {
	cin>>n>>m;
	int i,j;
	for(i=1;i<=m;i++) {
		int a,b;
		cin>>a>>b;
		map[a][b]=1;
	}
	for(i=1;i<=n;i++) {
		if(vis[i] == 0) DFS(i);
		if(t) {
			cout<<"Suspicious bugs found";
			return 0;
		}
	}
	cout<<"No suspicious bugs found!";
}