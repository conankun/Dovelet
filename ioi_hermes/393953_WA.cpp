#include<iostream>
#include<stdlib.h>
using namespace std;
int dis[3000][3000];
int chk[3000][3000];
int imsi[3000][3000];
int t;
struct A {
	int x,y;
};
A pos[100000];
int n;
int main() {
	int i,j;
	scanf("%d",&n);
	pos[1].x = 1001;
	pos[1].y = 1001;
	for(i=2;i<=n+1;i++) {
		scanf("%d%d",&pos[i].x,&pos[i].y);
		pos[i].x+=1001;
		pos[i].y+=1001;
	}
	for(i=1;i<=2001;i++) for(j=1;j<=2001;j++) imsi[i][j]=999999999;
	chk[1001][1001] = 1;
	dis[1001][1001] = 0;
	for(i=2;i<=n+1;i++) {
		for(j=1;j<=2001;j++) {
			if(dis[j][pos[i-1].x]+abs(pos[i-1].x-pos[i].x) < imsi[j][pos[i].x] && chk[j][pos[i-1].x] == i-1) {
				imsi[j][pos[i].x]=dis[j][pos[i-1].x]+abs(pos[i-1].x-pos[i].x);
			}
			if(dis[j][pos[i-1].x]+abs(j-pos[i].y) < imsi[pos[i].y][pos[i-1].x] && chk[j][pos[i-1].x] == i-1) {
				imsi[pos[i].y][pos[i-1].x]=dis[j][pos[i-1].x]+abs(j-pos[i].y);
			}
			if(dis[pos[i-1].y][j]+abs(j-pos[i].x) < imsi[pos[i-1].y][pos[i].x] && chk[pos[i-1].y][j] == i-1) {
				imsi[pos[i-1].y][pos[i].x]=dis[pos[i-1].y][j]+abs(j-pos[i].x);
			}
			if(dis[pos[i-1].y][j]+abs(pos[i-1].y-pos[i].y) < imsi[pos[i].y][j] && chk[pos[i-1].y][j] == i-1) {
				imsi[pos[i].y][j]=dis[pos[i-1].y][j]+abs(pos[i-1].y-pos[i].y);
			}
		}
		for(j=1;j<=2001;j++) {
			dis[pos[i].y][j] = imsi[pos[i].y][j];
			chk[pos[i].y][j] = i;
			dis[j][pos[i].x] = imsi[j][pos[i].x];
			chk[j][pos[i].x] = i;
			imsi[pos[i].y][j] = 999999999;
			imsi[j][pos[i].x] = 999999999;
		}
	}
	int ans=999999999;
	for(j=1;j<=2001;j++) {
		if(dis[pos[n+1].y][j] < ans && chk[pos[n+1].y][j] == n+1) {
			ans = dis[pos[n+1].y][j];
		}
		if(dis[j][pos[n+1].x] < ans && chk[j][pos[n+1].x] == n+1) {
			ans = dis[j][pos[n+1].x];
		}
	}
	printf("%d",ans);
}