#include<iostream>
using namespace std;
int n,m;
int map[2011][2011];
int vis[2011];
int chk[2011];
int notchk[2011][2011];
int path[100000];
int ind;
bool t=false;
void DFS(int bug,int before,int cnt) {
	if(vis[bug] != 0 && (vis[before]-vis[bug]+1)%2==1) {
		t=true;
		return;
	} else {
		vis[bug]=cnt;
		chk[bug]=1;
		int i;
		for(i=1;i<=n;i++) {
			if(map[bug][i] == 1 && notchk[bug][i] == 0)  {
				notchk[bug][i]=1;
				notchk[i][bug]=1;
				DFS(i,bug,cnt+1);
				notchk[bug][i]=0;
				notchk[i][bug]=0;
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
			DFS(i,0,1);
		}
		if(t) {
			cout<<"Suspicious bugs found!";
			return 0;
		}
	}
	cout<<"No suspicious bugs found!";
}