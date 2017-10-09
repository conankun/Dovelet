#include<stdio.h>
#include<stdlib.h>
struct POS {
	int x,y;
} pos[1000];
POS A,B,C;
int n;
int ccw(int ax,int ay,int bx,int by,int cx,int cy) {
	return (bx-ax)*(cy-ay) - (by-ay)*(cx-ax);
}
int main() {
	int i;
	scanf("%d%d%d%d%d%d",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
	printf("%.1lf\n",abs(A.x*(B.y-C.y)+B.x*(C.y-A.y)+C.x*(A.y-B.y))/2.00);
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&pos[i].x,&pos[i].y);
	int cnt=0;
	for(i=1;i<=n;i++) {
		if(ccw(A.x,A.y,B.x,B.y,pos[i].x,pos[i].y) >= 0) {
			if(ccw(B.x,B.y,C.x,C.y,pos[i].x,pos[i].y) >= 0) {
				if(ccw(C.x,C.y,A.x,A.y,pos[i].x,pos[i].y) >= 0) {
					cnt++;
				}
			}
		}
	}
	printf("%d",cnt);
}