#include<stdio.h>
int n;
char map[2001][2001];
int vis[2001][2001];
void DFS(int x,int y) {
	vis[y][x]=1;
	if(vis[y+1][x]==0 && map[y+1][x]=='*') {
		DFS(x,y+1);
	}
	if(vis[y-1][x]==0 && map[y-1][x]=='*') {
		DFS(x,y-1);
	}
	if(vis[y][x+1]==0 && map[y][x+1]=='*') {
		DFS(x+1,y);
	}
	if(vis[y][x-1]==0 && map[y][x-1]=='*') {
		DFS(x-1,y);
	}
}
int main() {
	scanf("%d\n",&n);
	int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			scanf("%c",&map[i][j]);
		}
		scanf("\n");
	}
	int cnt=0;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			if(vis[i][j]==0 && map[i][j]=='*') {
				cnt++;
				DFS(j,i);
			}
		}
	}
	printf("%d",cnt);
}