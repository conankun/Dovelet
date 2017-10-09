#include<stdio.h>
int N,K,P,map[100][100],sx,sy,ex,ey,circuit[99][999][2],dis[100][100],qu[10000][2],back[99][99][2],h=1,t,bt[10000][2];
int min(int a,int b){if(a<b)return a;return b;}
int max(int a,int b){if(a>b)return a;return b;}
int main() {
	scanf("%d",&N);
	scanf("%d%d%d%d",&sy,&sx,&ey,&ex);
	scanf("%d",&K);
	scanf("%d",&P);
	int i,j,k;
	for(i=1;i<=N;i++) for(j=1;j<=N;j++) {map[i][j]=1;dis[i][j]=-1;}
	for(i=1;i<=P;i++) {
		int n;
		scanf("%d",&n);
		for(j=1;j<=n;j++) {
			scanf("%d%d",&circuit[i][j][0],&circuit[i][j][1]);
			if(j>1) {
				if(circuit[i][j][0]==circuit[i][j-1][0]) {
					int s = min(circuit[i][j][1],circuit[i][j-1][1]);
					int s2= max(circuit[i][j][1],circuit[i][j-1][1]);
					for(k=s;k<=s2;k++) map[circuit[i][j][0]][k]=K;
					//y축 평행
				} else {
					int s = min(circuit[i][j][0],circuit[i][j-1][0]);
					int s2 = max(circuit[i][j][0],circuit[i][j-1][0]);
					for(k=s;k<=s2;k++) map[k][circuit[i][j][1]]=K;
					//x축평행
				}
			}
		}
	}
	int X=ex,Y=ey;
	qu[++t][0]=Y;
	qu[t][1]=X;
	dis[Y][X]=map[Y][X];
	int ansX,ansY,ans=-1;
	while(h<=t) {
		Y=qu[h][0],X=qu[h][1];
		if((dis[Y][X] < ans || ans==-1) && Y==sy && X == sx) {
			ans=dis[Y][X],ansX=X,ansY=Y;
		}
		if(dis[Y+1][X]>dis[Y][X]+map[Y+1][X] || dis[Y+1][X]==-1) {
			back[Y+1][X][0]=Y,back[Y+1][X][1]=X;
			dis[Y+1][X]=dis[Y][X]+map[Y+1][X];
			qu[++t][0]=Y+1;
			qu[t][1]=X;
		}
		if(dis[Y-1][X]>dis[Y][X]+map[Y-1][X] || dis[Y-1][X]==-1) {
			back[Y-1][X][0]=Y,back[Y-1][X][1]=X;
			dis[Y-1][X]=dis[Y][X]+map[Y-1][X];
			qu[++t][0]=Y-1;
			qu[t][1]=X;
		}
		if(dis[Y][X+1]>dis[Y][X]+map[Y][X+1] || dis[Y][X+1]==-1) {
			back[Y][X+1][0]=Y,back[Y][X+1][1]=X;
			dis[Y][X+1]=dis[Y][X]+map[Y][X+1];
			qu[++t][0]=Y;
			qu[t][1]=X+1;
		}
		if(dis[Y][X-1]>dis[Y][X]+map[Y][X-1] || dis[Y][X-1]==-1) {
			back[Y][X-1][0]=Y,back[Y][X-1][1]=X;
			dis[Y][X-1]=dis[Y][X]+map[Y][X-1];
			qu[++t][0]=Y;
			qu[t][1]=X-1;
		}
		h++;
	}
	printf("%d\n",ans);
	int path[11111][2];
	int index=0;
	Y=sy,X=sx;
	path[++index][0]=sy;
	path[index][1]=sx;
	while(back[Y][X][0]>0) {
		int yy=Y;
		Y=back[Y][X][0];
		X=back[yy][X][1];
		if(Y!=0&&X!=0) {
			path[++index][0]=Y;
			path[index][1]=X;
		}
	}
	int lastpath[11111][2];
	int ind=0;
	for(i=1;i<=index;i++) {
		if(i==1 || i==index) {
			lastpath[++ind][0]=path[i][0];
			lastpath[ind][1]=path[i][1];
		} else if(path[i][0]==path[i-1][0] && path[i][0] != path[i+1][0]) {
			lastpath[++ind][0]=path[i][0];
			lastpath[ind][1]=path[i][1];	
		} else if(path[i][1]==path[i-1][1] && path[i][1] != path[i+1][1]) {
			lastpath[++ind][0]=path[i][0];
			lastpath[ind][1]=path[i][1];
		}
	}
	printf("%d",ind);
	for(i=1;i<=ind;i++) {
		printf(" %d %d",lastpath[i][0],lastpath[i][1]);
	}
}