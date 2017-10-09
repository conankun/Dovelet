#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
struct A {
	int y,x,turn,level;
};
int Y,X;
int n;
A arr[1000];
int dis[1000];
int vis[1000][1000];
A pos;
int main() {
	scanf("%d%d",&X,&Y);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		int a,b;
		dis[i]=-1;
		scanf("%d%d",&a,&b);
		if(a==1) {
			arr[i].y=0;
			arr[i].x=b;
		} else if(a==2) {
			arr[i].y=Y;
			arr[i].x=b;
		} else if(a==3) {
			arr[i].y=b;
			arr[i].x=0;
		} else if(a == 4) {
			arr[i].y=b;
			arr[i].x=X;
		}
		arr[i].turn = a;
	}
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==1) {
		pos.y=0;
		pos.x=b;
	} else if(a==2) {
		pos.y=Y;
		pos.x=b;
	} else if(a==3) {
		pos.y=b;
		pos.x=0;
	} else if(a == 4) {
		pos.y=b;
		pos.x=X;
	}
	queue<A> qu;
	qu.push(pos);
	A aa;
	vis[pos.y][pos.x]=1;
	while(!qu.empty()) {
		int yy=qu.front().y;
		int xx = qu.front().x;
		if(qu.front().y > Y || qu.front().x > X || qu.front().y < 0 || qu.front().x < 0) {
			qu.pop();
			continue;
		}
		int levels = qu.front().level;
		for(i=1;i<=n;i++) {
			if((qu.front().level < dis[i] || dis[i] == -1) && qu.front().y == arr[i].y && qu.front().x == arr[i].x) {
				dis[i] = qu.front().level;
			}
		}
		aa.level = qu.front().level+1;
		if(qu.front().x == 0) {
			if(qu.front().y == 0) {
				if(vis[qu.front().y+1][qu.front().x]==0) {
					vis[qu.front().y+1][qu.front().x]=1;
					aa.y = qu.front().y+1;
					aa.x = qu.front().x;
					aa.level = qu.front().level+1;
					qu.push(aa);
				}
			} else {
				if(vis[qu.front().y+1][qu.front().x]==0) {
					vis[qu.front().y+1][qu.front().x]=1;
					aa.y = qu.front().y+1;
					aa.x = qu.front().x;
					qu.push(aa);
				}
				if(vis[qu.front().y-1][qu.front().x]==0) {
					vis[qu.front().y-1][qu.front().x]=1;
					aa.y = qu.front().y-1;
					aa.x = qu.front().x;
					qu.push(aa);
				}
			}
		}
		if(qu.front().y == 0) {
			if(qu.front().x == 0) {
				if(vis[qu.front().y][qu.front().x+1]==0) {
					vis[qu.front().y][qu.front().x+1]=1;
					aa.y = qu.front().y;
					aa.x = qu.front().x+1;
					qu.push(aa);
				}
			} else {
				if(vis[qu.front().y][qu.front().x+1]==0) {
					vis[qu.front().y][qu.front().x+1]=1;
					aa.y = qu.front().y;
					aa.x = qu.front().x+1;
					qu.push(aa);
				}
				if(vis[qu.front().y][qu.front().x-1]==0) {
					vis[qu.front().y][qu.front().x-1]=1;
					aa.y = qu.front().y;
					aa.x = qu.front().x-1;
					qu.push(aa);
				}
			}
		}
		if(qu.front().x == X) {
			if(qu.front().y == 0) {
				if(vis[qu.front().y+1][qu.front().x]==0) {
					vis[qu.front().y+1][qu.front().x]=1;
					aa.y = qu.front().y+1;
					aa.x = qu.front().x;
					qu.push(aa);
				}
			} else {
				if(vis[qu.front().y+1][qu.front().x]==0) {
					vis[qu.front().y+1][qu.front().x]=1;
					aa.y = qu.front().y+1;
					aa.x = qu.front().x;
					qu.push(aa);
				}
				if(vis[qu.front().y-1][qu.front().x]==0) {
					vis[qu.front().y-1][qu.front().x]=1;
					aa.y = qu.front().y-1;
					aa.x = qu.front().x;
					qu.push(aa);
				}
			}
		}
		if(qu.front().y == Y) {
			if(qu.front().x == 0) {
				if(vis[qu.front().y][qu.front().x+1]==0) {
					vis[qu.front().y][qu.front().x+1]=1;
					aa.y = qu.front().y;
					aa.x = qu.front().x+1;
					qu.push(aa);
				}
			} else {
				if(vis[qu.front().y][qu.front().x+1]==0) {
					vis[qu.front().y][qu.front().x+1]=1;
					aa.y = qu.front().y;
					aa.x = qu.front().x+1;
					qu.push(aa);
				}
				if(vis[qu.front().y][qu.front().x-1]==0) {
					vis[qu.front().y][qu.front().x-1]=1;
					aa.y = qu.front().y;
					aa.x = qu.front().x-1;
					qu.push(aa);
				}
			}
		}
		qu.pop();
	}
	int s=0;
	for(i=1;i<=n;i++) {
		s+=dis[i];
	}
	printf("%d",s);
}