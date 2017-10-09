#include<stdio.h>
int n;
char map[2001][2001];
int vis[2001][2001];
int Q[2000001][2];
int h=1,t;
void BFS(int x,int y) {
	h=1,t=0;
	Q[++t][0]=x;
	Q[t][1]=y;
	vis[y][x]=1;
	while(h<=t) {
		int yy=Q[h][1],xx=Q[h][0];
		if(vis[yy+1][xx]==0&&map[yy+1][xx]=='*') {
			Q[++t][0]=xx;
			Q[t][1]=yy+1;
			vis[yy+1][xx]=1;
		}
		if(vis[yy-1][xx]==0&&map[yy-1][xx]=='*') {
			Q[++t][0]=xx;
			Q[t][1]=yy-1;
			vis[yy-1][xx]=1;
		}
		if(vis[yy][xx+1]==0&&map[yy][xx+1]=='*') {
			Q[++t][0]=xx+1;
			Q[t][1]=yy;
			vis[yy][xx+1]=1;
		}
		if(vis[yy][xx-1]==0&&map[yy][xx-1]=='*') {
			Q[++t][0]=xx-1;
			Q[t][1]=yy;
			vis[yy][xx-1]=1;
		}
		h++;
	}
}
int main() {
	scanf("%d\n",&n);
	int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			scanf("%c",&map[i][j]);
		}
		if(i!=n) scanf("\n");
	}
	int cnt=0;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			if(vis[i][j]==0 && map[i][j]=='*') {
				cnt++;
				BFS(j,i);
			}
		}
	}
	printf("%d",cnt);
}