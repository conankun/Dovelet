#include<stdio.h>
struct A {
	double sy,sx,ey,ex;
	double y,x,plus;
}line[9999];
int N;
int main() {
	scanf("%d",&N);
	int i,j;
	for(i=1;i<=N;i++) {
		scanf("%d%d%d%d",&line[i].sx,&line[i].sy,&line[i].ex,&line[i].ey);
		line[i].y=1;
		line[i].x=(line[i].ey-line[i].sy)/(line[i].ex-line[i].sx);
		line[i].plus = line[i].sy - line[i].sx*line[i].x;
	}
	int ans=1;
	for(i=1;i<=N;i++) {
		int gu=0;
		for(j=1;j<=i-1;j++) {
			double xx,yy;
			if(line[i].sx != line[i].ex && line[i].sy != line[i].ey) {
				if(line[j].sx == line[j].ex) { // |
					xx = line[j].sx;
					yy = xx*line[i].x+line[i].plus;
				} else if(line[j].sy == line[j].ey) { // ㅡ
					yy=line[j].sy;
					xx = (yy-line[i].plus)/line[i].x;
				} else {
					double xxx = (-1*line[i].x)*(-1*line[j].x);
					double xxxx = (-1*line[j].x)*(-1*line[i].x);
					double yyy = line[i].y*(-1*line[j].x);
					double yyyy = line[j].y*(-1*line[i].x);
					double p=line[i].plus*(-1*line[j].x)-line[j].plus*(-1*line[i].x);
					yy = p/(yyy-yyyy);
					xx = (line[i].plus-yy*line[i].y)/(-1*line[i].x);
				}
			} else if(line[i].sx == line[i].ex) {
				if(line[j].sx == line[j].ex) continue;
				else if(line[j].sy == line[j].ey) {
					xx = line[i].sx;
					yy = line[j].sy;
				} else {
					xx = line[i].sx;
					yy = xx*line[j].x+line[j].plus;
				}
			} else if(line[i].sy == line[i].ey) {
				if(line[j].sy == line[j].ey) continue;
				else if(line[j].sx == line[j].ex) {
					xx = line[j].sx;
					yy = line[i].sy;
				} else {
					yy=line[i].sy;
					xx = (yy-line[j].plus)/line[j].x;
				}
			}
			if(-10<xx<10 && -10<yy<10) {
				gu++;
			}
		}
		ans+=(gu+1);
	}
	printf("%d",ans);

}