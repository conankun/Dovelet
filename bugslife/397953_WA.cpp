#include<iostream>
using namespace std;
int n,m;
int map[2011][2011];
int vis[2011];
int chk[2011];
bool t=false;
void DFS(int bug,int code) {
	if(vis[bug] == code) {
		t=true;
		return;
	} else {
		vis[bug]=code;
		chk[bug]=1;
		int i;
		for(i=1;i<=n;i++) {
			if(map[bug][i] == 1)  {
				DFS(i,code);
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
	}
	int cnt=0;
	for(i=1;i<=n;i++) {
		if(chk[i] == 0) DFS(i,++cnt);
		if(t) {
			cout<<"Suspicious bugs found!";
			return 0;
		}
	}
	cout<<"No suspicious bugs found!";
}