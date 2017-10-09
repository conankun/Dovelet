#include<stdio.h>
int max(int a,int b) {
	if(a>b) return a;
	return b;
}
int N,M;
char map[99][99];
int dis[99][99];
int sx,sy;
int qu[999][3];
int h=1,t;
struct A {
	int y,x;
}house[99];
int cnt;
int states[99];
int ans=99999999;
void bt(int level) {
	if(level==cnt+1) {
		int mx1=0,mx2=0;
		int s1=0,s2=0;
		int i;
		for(i=1;i<=cnt;i++) {
			if(states[i]==0) {
				s1+=dis[house[i].y][house[i].x]*2;
				if(mx1 < dis[house[i].y][house[i].x]) mx1 = dis[house[i].y][house[i].x];
			} else {
				s2+=dis[house[i].y][house[i].x]*2;
				if(mx2 < dis[house[i].y][house[i].x]) mx2 = dis[house[i].y][house[i].x];
			}
		}
		if(max(s1-mx1,s2-mx2) < ans) ans = max(s1-mx1,s2-mx2);
	} else {
		states[level]=0;
		bt(level+1);
		states[level]=1;
		bt(level+1);
	}
}
int main() {
	scanf("%d%d\n",&N,&M);
	int i,j;
	for(i=1;i<=N;i++) {
		for(j=1;j<=M;j++) {
			scanf("%c",&map[i][j]);	
			dis[i][j]=-1;
			if(map[i][j]=='S') {
				sx = j,sy=i;
			}
			if(map[i][j]=='H') {
				house[++cnt].y=i;
				house[cnt].x=j;
			}
		}
		scanf("\n");
	}
	dis[sy][sx]=0;
	qu[++t][0]=sy;
	qu[t][1]=sx;
	while(h<=t) {
		int x = qu[h][1];
		int y = qu[h][0];
		if(map[y+1][x]!='#'&&y+1<=N&&dis[y+1][x]==-1) {
			dis[y+1][x] = dis[y][x]+1;
			qu[++t][0]=y+1;
			qu[t][1]=x;
		}
		if(map[y-1][x]!='#'&&y-1>=1&&dis[y-1][x]==-1) {
			dis[y-1][x] = dis[y][x]+1;
			qu[++t][0]=y-1;
			qu[t][1]=x;
		}
		if(map[y][x+1]!='#'&&x+1<=M&&dis[y][x+1]==-1) {
			dis[y][x+1] = dis[y][x]+1;
			qu[++t][0]=y;
			qu[t][1]=x+1;
		}
		if(map[y][x-1]!='#'&&x-1>=1&&dis[y][x-1]==-1) {
			dis[y][x-1] = dis[y][x]+1;
			qu[++t][0]=y;
			qu[t][1]=x-1;
		}
		h++;
	}
	bt(1);
	printf("%d",ans);
}