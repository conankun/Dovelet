#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
struct POS {
	int x,y;
	bool operator<(const POS &P) const {
		return y < P.y;
	}
} pos[1000];
POS T[4];
int n;
int ccw(int ax,int ay,int bx,int by,int cx,int cy) {
	return (bx-ax)*(cy-ay) - (by-ay)*(cx-ax);
}
int main() {
	int i;
	scanf("%d%d%d%d%d%d",&T[1].x,&T[1].y,&T[2].x,&T[2].y,&T[3].x,&T[3].y);
	printf("%.1lf\n",abs(T[1].x*(T[2].y-T[3].y)+T[2].x*(T[3].y-T[1].y)+T[3].x*(T[1].y-T[2].y))/2.00);
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&pos[i].x,&pos[i].y);
	int cnt=0;
	std::sort(T+1,T+4);
	for(i=1;i<=n;i++) {
		if(ccw(T[1].x,T[1].y,T[2].x,T[2].y,pos[i].x,pos[i].y) >= 0) {
			if(ccw(T[2].x,T[2].y,T[3].x,T[3].y,pos[i].x,pos[i].y) >= 0) {
				if(ccw(T[3].x,T[3].y,T[1].x,T[1].y,pos[i].x,pos[i].y) >= 0) {
					cnt++;
				}
			}
		}
	}
	printf("%d",cnt);
}