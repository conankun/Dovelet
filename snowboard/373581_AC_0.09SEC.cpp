#include<iostream>
using namespace std;
int r,c;
int vis[1000][1000];
int map[1000][1000];
int mx=0;
void DFS(int i,int j,int len,int code) {
	if(i > r || j > c || i < 1 || j < 1) return;
	vis[i][j]=code;
	if(len > mx) mx = len;
	if(map[i-1][j] <= map[i][j] && vis[i-1][j] == 0) {
		vis[i-1][j]=code;
		DFS(i-1,j,len+1,code);
	}
	if(map[i+1][j] <= map[i][j] && vis[i+1][j] == 0) {
		vis[i+1][j]=code;
		DFS(i+1,j,len+1,code);
	}
	if(map[i][j+1] <= map[i][j] && vis[i][j+1] == 0) {
		vis[i][j+1]=code;
		DFS(i,j+1,len+1,code);
	}
	if(map[i][j-1] <= map[i][j] && vis[i][j-1] == 0) {
		vis[i][j-1]=code;
		DFS(i,j-1,len+1,code);
	}
	vis[i][j]=0;
}
int main() {
	cin>>r>>c;
	int i,j;
	for(i=1;i<=r;i++) {
		for(j=1;j<=c;j++) {
			cin>>map[i][j];
		}
	}
	int code=0;
	for(i=1;i<=r;i++) {
		for(j=1;j<=c;j++) {
			code++;
			DFS(i,j,1,code);
		}
	}
	cout<<mx;
}