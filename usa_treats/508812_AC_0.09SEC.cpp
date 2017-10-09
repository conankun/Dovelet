#include<stdio.h>
int W,H,arr[100][100],islock[100],islock2[100],imsi[100];
int min(int a,int b){if(a<b) return a;return b;}
int max(int a,int b){if(a>b) return a;return b;}
int main() {
	scanf("%d%d",&W,&H);
	int i,j,k,l;
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
				if(islock[i]==0&&islock2[j]==0) {
					xx=j;
					yy=i;
					break;
				} else {
					bool t=true;
					if(x==j&&islock[i]==0&&islock[y]==0) {
						for(l=min(y,i);l<=max(y,i);l++) {
							if(arr[l][j]>mx) {t=false;break;}
						}
						if(t) {
							xx=j;
							yy=i;
							break;
						}
					}
					if(y==i&&islock2[x]==0&&islock2[j]==0) {
						for(l=min(x,j);l<=max(x,j);l++) {
							if(arr[i][l]>mx) {t=false;break;}
						}
						if(t) {
							xx=j;
							yy=i;
							break;
						}
					}
				}
			}
			if(xx!=0&&yy!=0) break;
		}
		if(xx!=0&&yy!=0 && (yy<y || (yy==y&&xx<x))) {
			for(i=1;i<=H;i++) imsi[i]=arr[i][x];
			for(i=1;i<=H;i++) arr[i][x]=arr[i][xx];
			for(i=1;i<=H;i++) arr[i][xx]=imsi[i];
			islock2[xx]=1;
			//
			for(i=1;i<=W;i++) imsi[i]=arr[y][i];
			for(i=1;i<=W;i++) arr[y][i]=arr[yy][i];
			for(i=1;i<=W;i++) arr[yy][i]=imsi[i];
			islock[yy]=1;
		} else {
			for(i=1;i<=H;i++) {
				islock2[x]=1;
			}
			islock[y]=1;
		}
		beforemx=mx;
	}
	for(i=1;i<=H;i++,printf("\n")) for(j=1;j<=W;j++) printf("%d ",arr[i][j]);
}