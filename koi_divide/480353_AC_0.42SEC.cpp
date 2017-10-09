#include<stdio.h>
#include<float.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct A {
	long double sy,sx,ey,ex;
	long double y,x,plus;
}line[9999];
int N;
long double c;
long double xxxxx,yyyyy;
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d",&N);
	int i,j;
	for(i=1;i<=N;i++) {
		scanf("%Lf%Lf%Lf%Lf",&line[i].sx,&line[i].sy,&line[i].ex,&line[i].ey);
		if(line[i].sx>line[i].ex) {
			long double tmp1=line[i].sy,tmp2=line[i].sx;
			line[i].sy = line[i].ey;
			line[i].sx = line[i].ex;
			line[i].ey = tmp1;
			line[i].ex = tmp2;
		}
		line[i].y=1;
		line[i].x=(line[i].ey-line[i].sy)/(line[i].ex-line[i].sx);
		line[i].plus = line[i].sy - line[i].sx*line[i].x;
	}
	int ans=1;
	int gusum=0;
	for(i=1;i<=N;i++) {
		int gu=0,t=0;
		c;
		for(c=-10;c<=10;c+=0.0001)
		if(-10<line[i].x*c+line[i].plus && line[i].x*c+line[i].plus < 10 && (c >= line[i].sx || fabs(c-line[i].sx) < 0.000000000000001)&& (c<=line[i].ex||fabs(c-line[i].ex) < 0.000000000000001)) {
			t=1;
			break;
		}
		for(j=1;j<=i-1;j++) {
			long double xx,yy;
			if(fabs(line[i].sx - line[i].ex) > 0.000000000000001 && fabs(line[i].sy - line[i].ey) > 0.000000000000001) {
				if(fabs(line[j].x - line[i].x)<0.000000000000001) {
					continue;
				}
				if(fabs(line[j].sx - line[j].ex)<0.000000000000001) { // |
					xx = line[j].sx;
					yy = xx*line[j].x+line[j].plus;
				} else if(fabs(line[j].sy - line[j].ey)<0.000000000000001) { // ㅡ
					yy=line[j].sy;
					xx = (yy-line[j].plus)/line[j].x;
				} else {
					long double p=line[i].plus-line[j].plus;
					xx = p/(-line[i].x+line[j].x);
					yy = xx*line[i].x+line[i].plus;
				}
			} else if(fabs(line[i].sx - line[i].ex)<0.000000000000001) {
				if(fabs(line[j].sx - line[j].ex)<0.000000000000001) continue;
				else if(fabs(line[j].sy - line[j].ey)<0.000000000000001) {
					xx = line[i].sx;
					yy = line[j].sy;
				} else {
					xx = line[i].sx;
					yy = xx*line[j].x+line[j].plus;
				}
			} else if(fabs(line[i].sy - line[i].ey)<0.000000000000001) {
				if(fabs(line[j].sy - line[j].ey)<0.000000000000001) continue;
				else if(fabs(line[j].sx - line[j].ex)<0.000000000000001) {
					xx = line[j].sx;
					yy = line[i].sy;
				} else {
					yy=line[i].sy;
					xx = (yy-line[j].plus)/line[j].x;
				}
			}
			if(-10<xx && xx<10 && -10<yy&&yy<10 && xx-line[i].sx && xx<=line[i].ex&&xx>=line[j].sx&&xx<=line[j].ex) {
				if(fabs(xx-10) < 0.000000000001 || fabs(-10-xx) < 0.000000000001 || fabs(-10-yy) < 0.000000000001 || fabs(10-yy) < 0.000000000001) {
					continue;
				}
				xxxxx=xx;
				yyyyy=yy;
				gu++;
				
			}
		}
		if(t) {
			ans+=gu+1;
			gusum+=gu;
		}
	}
	printf("%d",ans);
}