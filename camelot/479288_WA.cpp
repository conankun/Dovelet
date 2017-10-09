#include<stdio.h>
#include<string.h>
struct A {
	int y,x,state,level;
}unit[1000],qu[10000];
int cnt,h,t;
int vis[50][30];
int dis[100][50][30][50][30];
int R,C;
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d\n",&R,&C);
	char aa;int bb;
	while(scanf("%c\n%d\n",&aa,&bb) != -1) {
		unit[++cnt].x = aa-'A'+1;
		unit[cnt].y = bb;
		if(cnt==1) unit[cnt].state=0;
		else unit[cnt].state=1;
	}
	int d,i,j,k,l;
	for(d=1;d<=cnt;d++)
	for(i=1;i<=R;i++) {
		for(j=1;j<=C;j++) {
			h=1,t=0;
			for(k=1;k<=R;k++) for(l=1;l<=C;l++) vis[k][l]=0;
			if(d==1) {
				qu[++t].x = j;
				qu[t].y = i;
				qu[t].level=0;
				vis[i][j]=1;
				while(h<=t) {
					int x = qu[h].x;
					int y = qu[h].y;
					int level = qu[h].level;
					dis[d][i][j][y][x]=level;
					if(vis[y+1][x]==0 && y+1<=R) {
						vis[y+1][x]=1;
						qu[++t].x = x;
						qu[t].y = y+1;
						qu[t].level = level+1;
					}
					if(vis[y-1][x]==0 && y-1>=1) {
						vis[y-1][x]=1;
						qu[++t].x = x;
						qu[t].y = y-1;
						qu[t].level = level+1;
					}
					if(vis[y][x+1]==0 && x+1<=C) {
						vis[y][x+1]=1;
						qu[++t].x = x+1;
						qu[t].y = y;
						qu[t].level = level+1;
					}
					if(vis[y][x-1]==0 && x-1>=1) {
						vis[y][x-1]=1;
						qu[++t].x = x-1;
						qu[t].y = y;
						qu[t].level = level+1;
					}
					if(vis[y+1][x+1]==0&&y+1<=R&&x+1<=C) {
						vis[y+1][x+1]=1;
						qu[++t].x = x+1;
						qu[t].y = y+1;
						qu[t].level = level+1;
					}
					if(vis[y+1][x-1]==0&&y+1<=R&&x-1>=1) {
						vis[y+1][x-1]=1;
						qu[++t].x = x-1;
						qu[t].y = y+1;
						qu[t].level = level+1;
					}		
					if(vis[y-1][x+1]==0&&y-1>=1&&x+1<=C) {
						vis[y-1][x+1]=1;
						qu[++t].x = x+1;
						qu[t].y = y-1;
						qu[t].level = level+1;
					}
					if(vis[y-1][x-1]==0&&y-1>=1&&x-1>=1) {
						vis[y-1][x-1]=1;
						qu[++t].x = x-1;
						qu[t].y = y-1;
						qu[t].level = level+1;
					}
					h++;
				}
			} else {
				qu[++t].x = j;
				qu[t].y = i;
				qu[t].level=0;
				vis[i][j]=1;
				while(h<=t) {
					int x = qu[h].x;
					int y = qu[h].y;
					int level = qu[h].level;
					dis[d][i][j][y][x]=level;
					if(vis[y+1][x+2]==0 && y+1<=R && x+2<=C) {
						vis[y+1][x+2]=1;
						qu[++t].x = x+2;
						qu[t].y = y+1;
						qu[t].level = level+1;
					}
					if(vis[y+1][x-2]==0 && y+1 <= R && x-2 >=1) {
						vis[y+1][x-2]=1;
						qu[++t].x = x-2;
						qu[t].y = y+1;
						qu[t].level = level+1;
					}
					if(vis[y-1][x+2]==0 && x+2<=C && y-1 >=1) {
						vis[y-1][x+2]=1;
						qu[++t].x = x+2;
						qu[t].y = y-1;
						qu[t].level = level+1;
					}
					if(vis[y-1][x-2]==0 && x-2>=1 && y-1>=1) {
						vis[y-1][x-2]=1;
						qu[++t].x = x-2;
						qu[t].y = y-1;
						qu[t].level = level+1;
					}
					if(vis[y+2][x+1]==0&&y+2<=R&&x+1<=C) {
						vis[y+2][x+1]=1;
						qu[++t].x = x+1;
						qu[t].y = y+2;
						qu[t].level = level+1;
					}
					if(vis[y+2][x-1]==0&&y+2<=R&&x-1>=1) {
						vis[y+2][x-1]=1;
						qu[++t].x = x-1;
						qu[t].y = y+2;
						qu[t].level = level+1;
					}
					if(vis[y-2][x+1]==0&&y-2>=1&&x+1<=C) {
						vis[y-2][x+1]=1;
						qu[++t].x = x+1;
						qu[t].y = y-2;
						qu[t].level = level+1;
					}
					if(vis[y-2][x-1]==0&&y-2>=1&&x-1>=1) {
						vis[y-2][x-1]=1;
						qu[++t].x = x-1;
						qu[t].y = y-2;
						qu[t].level = level+1;
					}
					h++;
				}
			}
		}
	}
	int ans=99999999;
	for(i=1;i<=R;i++) {
		for(j=1;j<=C;j++) {
			int king = dis[1][unit[1].y][unit[1].x][i][j];
			int auther=0;
			for(d=2;d<=cnt;d++) {
				auther+=dis[d][unit[d].y][unit[d].x][i][j];
			}
			if(king+auther < ans) ans = king+auther;
			for(d=2;d<=cnt;d++) {
				for(k=1;k<=R;k++) {
					for(l=1;l<=C;l++) {
						if(auther-dis[d][unit[d].y][unit[d].x][i][j]+dis[d][unit[d].y][unit[d].x][k][l]+dis[d][k][l][i][j]+dis[1][unit[1].y][unit[1].x][k][l] < ans) ans = auther-dis[d][unit[d].y][unit[d].x][i][j]+dis[d][unit[d].y][unit[d].x][k][l]+dis[d][k][l][i][j]+dis[1][unit[1].y][unit[1].x][k][l];
					}
				}
			}
		}
	}
	printf("%d",ans);
}