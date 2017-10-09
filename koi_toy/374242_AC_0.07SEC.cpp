#include<iostream>
using namespace std;
int n,m;
int pl[1000][1000];
int isRoot[1000];
int vis[1000];
int con[1000][1000];
int cntRoot;
void DFS(int ind) {
	vis[ind]=1;
	int i,j;
	for(i=1;i<=n;i++) {
		if(pl[ind][i] > 0) {
			if(vis[i] == 0) DFS(i);
			for(j=1;j<=n;j++) {
				con[ind][j]+=con[i][j]*pl[ind][i];
			}
			if(isRoot[i] == 1) {
				con[ind][i]+=pl[ind][i];
			}
		}
	}
}
int main() {
	cin>>n>>m;
	int i,j;
	for(i=1;i<=m;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		pl[a][b]+=c;
	}
	for(i=1;i<=n;i++) {
		bool t=true;
		for(j=1;j<=n;j++) {
			if(pl[i][j] > 0) {
				t=false;
				break;
			}
		}
		if(t) {
			isRoot[i]=1;
			cntRoot++;
		}
	}
	DFS(n);
	cout<<cntRoot<<endl;
	for(i=1;i<=n;i++) {
		if(isRoot[i] == 1) {
			cout<<i<<" "<<con[n][i]<<endl;
		}
	}
}