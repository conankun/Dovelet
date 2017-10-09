#include<iostream>
using namespace std;
char map[100][100];
int vis[100][100];
int n,m,a,b;//(y,x)(y,x)
void DFS(int i,int j) {
	vis[i][j]=1;
	if(vis[i+1][j] == 0 && map[i+1][j] == 'X') {
		vis[i+1][j]=1;
		DFS(i+1,j);
	}
	if(vis[i-1][j] == 0 && map[i-1][j] == 'X') {
		vis[i-1][j]=1;
		DFS(i-1,j);
	}
	if(vis[i][j+1] == 0 && map[i][j+1] == 'X') {
		vis[i][j+1]=1;
		DFS(i,j+1);
	}
	if(vis[i][j-1] == 0 && map[i][j-1] == 'X') {
		vis[i][j-1]=1;
		DFS(i,j-1);
	}
	if(vis[i-1][j-1] == 0 && map[i-1][j-1] == 'X') {
		vis[i-1][j-1]=1;
		DFS(i-1,j-1);
	}
	if(vis[i-1][j+1] == 0 && map[i-1][j+1] == 'X') {
		vis[i-1][j+1]=1;
		DFS(i-1,j+1);
	}
	if(vis[i+1][j-1] == 0 && map[i+1][j-1] == 'X') {
		vis[i+1][j-1]=1;
		DFS(i+1,j-1);
	}
	if(vis[i+1][j+1] == 0 && map[i+1][j+1] == 'X') {
		vis[i+1][j+1]=1;
		DFS(i+1,j+1);
	}
}
int main() {
	int i,j;
	cin>>n>>m>>a>>b;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			cin>>map[i][j];
		}
	}
	DFS(a,b);
	int sum=0;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			if(vis[i][j]==1) {
				if(vis[i+1][j] == 0) {
					sum++;
				}
				if(vis[i-1][j] == 0) {
					sum++;
				}
				if(vis[i][j+1] == 0) {
					sum++;
				}
				if(vis[i][j-1] == 0) {
					sum++;
				}
			}
		}
	}
	cout<<sum;
}