#include<iostream>
using namespace std;
int n,m;
int map[2011][2011];
int vis[2011];
int chk[2011];
bool t=false;
void DFS(int bug,int before) {
	if(vis[bug] == 1) {
		t=true;
		return;
	} else {
		vis[bug]=1;
		chk[bug]=1;
		int i;
		for(i=1;i<=n;i++) {
			if(map[bug][i] == 1 && i != before)  {
				DFS(i,bug);
			}
		}
		vis[bug]=0;
	}
}
int main() {
	cin>>n>>m;
	int i,j;
	for(i=1;i<=m;i++) {
		int a,b;
		cin>>a>>b;
		map[a][b]=1;
		map[b][a]=1;
	}
	for(i=1;i<=n;i++) {
		if(chk[i] == 0) {
			DFS(i,0);
		}
		if(t) {
			cout<<"Suspicious bugs found!";
			return 0;
		}
	}
	cout<<"No suspicious bugs found!";
}