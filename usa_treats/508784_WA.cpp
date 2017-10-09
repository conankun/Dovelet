#include<stdio.h>
int W,H,arr[100][100],islock[100][100],imsi[100];
int main() {
	scanf("%d%d",&W,&H);
	int i,j,k;
	for(i=1;i<=H;i++) {
		for(j=1;j<=W;j++) {
			scanf("%d",&arr[i][j]);
		}
	}
	int beforemx=999999999;
	for(k=1;k<=H*W;k++) {
		int mx=0,x=0,y=0;
		for(i=1;i<=H;i++) {
			for(j=1;j<=W;j++) {
				if(beforemx > arr[i][j]&& mx < arr[i][j]) {
					mx=arr[i][j];
					x=j;
					y=i;
				}
			}
		}
		int xx=0,yy=0;
		for(i=1;i<=H;i++) {
			for(j=1;j<=W;j++) {
				if(islock[i][j]==0) {
					xx=j;
					yy=i;
					break;
				}
			}
			if(xx!=0&&yy!=0) break;
		}
		if(xx!=0&&yy!=0 && (yy<y || (yy==y&&xx<x))) {
			for(i=1;i<=H;i++) imsi[i]=arr[i][x];
			for(i=1;i<=H;i++) arr[i][x]=arr[i][xx];
			for(i=1;i<=H;i++) arr[i][xx]=imsi[i];
			for(i=1;i<=H;i++) {
				islock[i][xx]=1;
			}
			//
			for(i=1;i<=W;i++) imsi[i]=arr[y][i];
			for(i=1;i<=W;i++) arr[y][i]=arr[yy][i];
			for(i=1;i<=W;i++) arr[yy][i]=imsi[i];
			for(i=1;i<=W;i++) {
				islock[yy][i]=1;
			}
		} else {
			for(i=1;i<=H;i++) {
				islock[i][x]=1;
			}
			for(i=1;i<=W;i++) {
				islock[y][i]=1;
			}
		}
		beforemx=mx;
	}
	
	for(i=1;i<=H;i++,printf("\n")) for(j=1;j<=W;j++) printf("%d ",arr[i][j]);
}