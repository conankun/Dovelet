#include<stdio.h>
#include<float.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct A {
	double sy,sx,ey,ex;
	double y,x,plus;
}line[9999];
int chk[999],co[999];
int N;
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d",&N);
	int i,j;
	for(i=1;i<=N;i++) {
		scanf("%lf%lf%lf%lf",&line[i].sx,&line[i].sy,&line[i].ex,&line[i].ey);
		if(line[i].sx>line[i].ex) {
			double tmp1=line[i].sy,tmp2=line[i].sx;
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
	for(i=1;i<=N;i++) {
		int gu=0,t=0;
		double c;
		for(c=-10;c<=10;c+=0.0001)
		if((-10<line[i].x*c+line[i].plus || fabs(-10-(line[i].x*c+line[i].plus)) < 0.0000000001) && (line[i].x*c+line[i].plus < 10 || fabs(10-(line[i].x*c+line[i].plus))) && c >= line[i].sx && c<=line[i].ex) {
			t=1;
			break;
		}
		for(j=1;j<=i-1;j++) {
			double xx,yy;
			if(fabs(line[i].sx - line[i].ex) > 0.000000001 && fabs(line[i].sy - line[i].ey) > 0.0000000001) {
				if(fabs(line[j].x - line[i].x)<0.00000001) {
					continue;
				}
				if(fabs(line[j].sx - line[j].ex)<0.00000001) { // |
					xx = line[j].sx;
					yy = xx*line[j].x+line[j].plus;
				} else if(fabs(line[j].sy - line[j].ey)<0.00000001) { // ㅡ
					yy=line[j].sy;
					xx = (yy-line[j].plus)/line[j].x;
				} else {
					double p=line[i].plus-line[j].plus;
					xx = p/(-line[i].x+line[j].x);
					yy = xx*line[i].x+line[i].plus;
				}
			} else if(fabs(line[i].sx - line[i].ex)<0.00000001) {
				if(fabs(line[j].sx - line[j].ex)<0.00000001) continue;
				else if(fabs(line[j].sy - line[j].ey)<0.00000001) {
					xx = line[i].sx;
					yy = line[j].sy;
				} else {
					xx = line[i].sx;
					yy = xx*line[j].x+line[j].plus;
				}
			} else if(fabs(line[i].sy - line[i].ey)<0.00000001) {
				if(fabs(line[j].sy - line[j].ey)<0.00000001) continue;
				else if(fabs(line[j].sx - line[j].ex)<0.00000001) {
					xx = line[j].sx;
					yy = line[i].sy;
				} else {
					yy=line[i].sy;
					xx = (yy-line[j].plus)/line[j].x;
				}
			}
			if(-10<xx && xx<10 && -10<yy&&yy<10 && chk[j] && xx >= line[i].sx && xx<=line[i].ex&&xx>=line[j].sx&&xx<=line[j].ex) {
				gu++;
			}
		}
		if(t) {
			ans+=gu+1;
		}
		chk[i]=t;
		co[i]=gu;
		if(!t) co[i]=-1;
	}
	printf("%d",ans);

}