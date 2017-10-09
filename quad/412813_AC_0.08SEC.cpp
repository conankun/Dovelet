#include<stdio.h>
int n;
int map[1000][1000];
int ans[1000][1000];
int index[1000];
int bin[1000000];
int ind;
void divcon(int sx,int sy,int ex,int ey,int level) {
	int i,j;
	bool t=true;
	int x=map[sy][sx];
	for(i=sy;i<=ey;i++) {
		for(j=sx;j<=ex;j++) {
			if(map[i][j] != x) {
				t=false;
				break;
			}
		}
		if(!t) break;
	}
	if(t) {
		ans[level][++index[level]]=0;
		ans[level][++index[level]]=x;
	} else {
		ans[level][++index[level]]=1;
		divcon(sx,sy,(sx+ex)/2,(sy+ey)/2,level+1);
		divcon((sx+ex)/2+1,sy,ex,(sy+ey)/2,level+1);
		divcon(sx,(sy+ey)/2+1,(sx+ex)/2,ey,level+1);
		divcon((sx+ex)/2+1,(sy+ey)/2+1,ex,ey,level+1);
	}
}
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			scanf("%d",&map[i][j]);
		}
	}
	divcon(1,1,n,n,1);
	for(i=1;i<=n;i++) {
		for(j=1;j<=index[i];j++) {
			bin[++ind]=ans[i][j];
		}
	}
	int d=ind%4;
	int sum=0;
	int g=1;
	for(i=d;i>=1;i--) {
		sum+=g*bin[i];
		g*=2;
	}
	printf("%X",sum);
	for(i=d+1;i<=ind;i+=4) {
		g=1;
		sum=0;
		for(j=i+3;j>=i;j--) {
			sum+=g*bin[j];
			g*=2;
		}
		printf("%X",sum);
	}
}