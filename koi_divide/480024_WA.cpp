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
		scanf("%lf%lf%lf%lf",&line[i].sx,&line[i].sy,&line[i].ex,&line[i].ey);
		line[i].y=1;
		line[i].x=(line[i].ey-line[i].sy)/(line[i].ex-line[i].sx);
		line[i].plus = line[i].sy - line[i].sx*line[i].x;
	}
	int ans=1;
	line[N+1].sy=-10,line[N+1].ey=-10,line[N+1].sx = -10,line[N+1].ex=10;
	line[N+2].sy=10,line[N+2].ey=10,line[N+2].sx = -10,line[N+2].ex=10;
	line[N+3].sy=-10,line[N+3].ey=10,line[N+3].sx = 10,line[N+3].ex=10;
	line[N+4].sy=-10,line[N+4].ey=10,line[N+4].sx = 10,line[N+4].ex=10;
	for(i=1;i<=N;i++) {
		int gu=0,t=0;
		for(j=N+1;j<=N+4;j++) {
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
			if(-10<=xx && xx<=10 && -10<=yy&&yy<=10) {
				t=1;
			}
		}
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
			if(-10<xx && xx<10 && -10<yy&&yy<10) {
				gu++;
			}
		}
		if(t) ans+=(gu+1);
	}
	printf("%d",ans);

}