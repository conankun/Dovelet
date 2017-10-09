#include <cstdio>
#include <cmath>
#define EPSILON 0.00000001
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
static int n;
typedef struct{
	double x;
	double y;
}point;
typedef struct{
	point p1,p2;
}segment;
typedef struct{
	double a;
	double b;
	double c;
}line;
segment save[110];
segment tmp1,tmp2,tmp3,tmp4;
void points_to_line(point p1,point p2,line *l){
	if(p1.x==p2.x){
		l->a=1;
		l->b=0;
		l->c=-p1.x;
	} else{
		l->b=1;
		l->a=-(p1.y-p2.y)/(p1.x-p2.x);
		l->c=-(l->a*p1.x)-(l->b*p1.y);
	}
}
bool parallelq(line l1,line l2){
	return ((fabs(l1.a-l2.a)<=EPSILON)&&(fabs(l1.b-l2.b))<=EPSILON);
}
bool same_lineq(line l1,line l2){
	return (parallelq(l1,l2)&&(fabs(l1.c-l2.c)<=EPSILON));
}
bool same_point(point p1,point p2){
	return (fabs(p1.x-p2.x)<=EPSILON&&fabs(p1.y-p2.y)<=EPSILON);
}
bool check_boundary(point p){
	if(p.x>=-10&&p.x<=10&&(fabs(p.y+10)<=EPSILON||fabs(p.y-10)<=EPSILON)) return true;
			if(p.y>=-10&&p.y<=10&&(fabs(p.x+10)<=EPSILON||fabs(p.x-10)<=EPSILON)) return true;
			if(p.x<-10||p.x>10||p.y<-10||p.y>10){
				if(p.x<-10){
					if(fabs(p.x+10)<=EPSILON){
						if(p.y<=10&&p.y>=-10) return true;
						else{
							if(p.y>10) {
								if(fabs(p.y-10)<=EPSILON) return true;
								else return false;
								}
							if(p.y<-10){
								if(fabs(p.y+10)<=EPSILON) return true;
								else return false;
							}
						}
					}
					else return false;
				}
				if(p.x>10){
					if(fabs(p.x-10)<=EPSILON){
						if(p.y<=10&&p.y>=-10) return true;
						else{
							if(p.y>10) {
								if(fabs(p.y-10)<=EPSILON) return true;
								else return false;
								}
							if(p.y<-10){
								if(fabs(p.y+10)<=EPSILON) return true;
								else return false;
							}
						}
					}
					else return false;
				}
			if(p.y<-10){
					if(fabs(p.y+10)<=EPSILON){
						if(p.x<=10&&p.x>=-10) return true;
						else{
							if(p.x>10) {
								if(fabs(p.x-10)<=EPSILON) return true;
								else return false;
								}
							if(p.x<-10){
								if(fabs(p.x+10)<=EPSILON) return true;
								else return false;
							}
						}
					}
					else return false;
				}
			if(p.y>10){
					if(fabs(p.y-10)<=EPSILON){
						if(p.x<=10&&p.x>=-10) return true;
						else{
							if(p.x>10) {
								if(fabs(p.x-10)<=EPSILON) return true;
								else return false;
								}
							if(p.x<-10){
								if(fabs(p.x+10)<=EPSILON) return true;
								else return false;
							}
						}
					}
					else return false;
				}
			}
return false;
}
bool check_external(point p){
	if(p.x>10||p.x<-10||p.y>10||p.y<-10) return true;
	else return false;
}
void intersection_point(line l1,line l2,point *p){
	p->x=(l2.b*l1.c-l1.b*l2.c)/(l2.a*l1.b-l1.a*l2.b);
	if(fabs(l1.b)>EPSILON)	//수직선인지 확인
		p->y=-(l1.a*p->x+l1.c)/l1.b;
	else
		p->y=-(l2.a*p->x+l2.c)/l2.b;
}
bool point_in_box(point p,point b1,point b2){
	double pxmin=min(b1.x,b2.x);
	double pymin=min(b1.y,b2.y);
	double pxmax=max(b1.x,b2.x);
	double pymax=max(b1.y,b2.y);
	if(p.x>=pxmin&&p.x<=pxmax&&p.y>=pymin&&p.y<=pymax) {
		return true;}
	else {
		if(p.x<pxmin&&p.y>=pymin&&p.y<=pymax&&fabs(p.x-pxmin)<=EPSILON) return true;
		if(p.x>pxmax&&p.y>=pymin&&p.y<=pymax&&fabs(p.x-pxmax)<=EPSILON) return true;
		if(p.y<pymin&&p.x>=pxmin&&p.x<=pxmax&&fabs(p.y-pymin)<=EPSILON) return true;
		if(p.y>pymax&&p.x>=pxmin&&p.x<=pxmax&&fabs(p.y-pymax)<=EPSILON) return true;
		if(p.x<pxmin&&p.y>pymax&&fabs(p.x-pxmin)<=EPSILON&&fabs(p.y-pymax)<=EPSILON) return true;
		if(p.x<pxmin&&p.y<pymin&&fabs(p.x-pxmin)<=EPSILON&&fabs(p.y-pymin)<=EPSILON) return true;
		if(p.x>pxmax&&p.y>pymax&&fabs(p.x-pxmax)<=EPSILON&&fabs(p.y-pymax)<=EPSILON) return true;
		if(p.x>pxmax&&p.y<pymin&&fabs(p.x-pxmax)<=EPSILON&&fabs(p.y-pymin)<=EPSILON) return true;
	}
return false;
}
bool segments_intersect(segment s1,segment s2){
	line l1,l2;
	point p;
	points_to_line(s1.p1,s1.p2,&l1);
	points_to_line(s2.p1,s2.p2,&l2);
	if(parallelq(l1,l2)) return false;
	intersection_point(l1,l2,&p);
	return(point_in_box(p,s1.p1,s1.p2)&&point_in_box(p,s2.p1,s2.p2));
}
bool cut_square(segment s1){
	int counter=0,cnt1=0;
	point aa[2];
	point test1,test2;
	line Line1,Line2;
	if(segments_intersect(s1,tmp1)) {
	counter++;
	test1.x=tmp1.p1.x;test1.y=tmp1.p1.y;
	test2.x=tmp1.p2.x;test2.y=tmp1.p2.y;
	points_to_line(test1,test2,&Line1);
	test1.x=s1.p1.x;test1.y=s1.p1.y;
	test2.x=s1.p2.x;test2.y=s1.p2.y;
	points_to_line(test1,test2,&Line2);
	intersection_point(Line1,Line2,&aa[cnt1++]);
	}
	if(segments_intersect(s1,tmp2)) {
	counter++;
	test1.x=tmp2.p1.x;test1.y=tmp2.p1.y;
	test2.x=tmp2.p2.x;test2.y=tmp2.p2.y;
	points_to_line(test1,test2,&Line1);
	test1.x=s1.p1.x;test1.y=s1.p1.y;
	test2.x=s1.p2.x;test2.y=s1.p2.y;
	points_to_line(test1,test2,&Line2);
	intersection_point(Line1,Line2,&aa[cnt1++]);
	}
	if(segments_intersect(s1,tmp3)) {
	if(cnt1>=2) return true;
	counter++;
	test1.x=tmp3.p1.x;test1.y=tmp3.p1.y;
	test2.x=tmp3.p2.x;test2.y=tmp3.p2.y;
	points_to_line(test1,test2,&Line1);
	test1.x=s1.p1.x;test1.y=s1.p1.y;
	test2.x=s1.p2.x;test2.y=s1.p2.y;
	points_to_line(test1,test2,&Line2);
	intersection_point(Line1,Line2,&aa[cnt1++]);
	}
	if(segments_intersect(s1,tmp4)) {
	if(cnt1>=2) return true;
	counter++;
	test1.x=tmp4.p1.x;test1.y=tmp4.p1.y;
	test2.x=tmp4.p2.x;test2.y=tmp4.p2.y;
	points_to_line(test1,test2,&Line1);
	test1.x=s1.p1.x;test1.y=s1.p1.y;
	test2.x=s1.p2.x;test2.y=s1.p2.y;
	points_to_line(test1,test2,&Line2);
	intersection_point(Line1,Line2,&aa[cnt1++]);
	}
	if(cnt1>=1){
		if(same_point(aa[0],aa[1])) return false;
	}
	if(counter>=2) return true;
	else return false;
}
void increasing_solution(int cnt1,segment s1,int *ans){
	int f1=0,f2=0,f3=0;
	point test1,test2,test3;
	line Line1,Line2;
	if(cnt1==0) {(*ans)+=1;return;}
	for(int i=0;i<cnt1;i++){
		if(segments_intersect(s1,save[i])){
				test1.x=s1.p1.x;test1.y=s1.p1.y;
				test2.x=s1.p2.x;test2.y=s1.p2.y;
				points_to_line(test1,test2,&Line1);
				test1.x=save[i].p1.x;test1.y=save[i].p1.y;
				test2.x=save[i].p2.x;test2.y=save[i].p2.y;
				points_to_line(test1,test2,&Line2);
				intersection_point(Line1,Line2,&test3);
				if(check_external(test3))	f1++;			//교차하는 점이 정사각형 외부
				else if(check_boundary(test3)) f2++;		//교차하는 점이 정사각형 경계
				else f3++;									//교차하는 점이 정사각형 내부
		}
	}
	if(f1==0&&f2==0&&f3==0) (*ans)+=1;
	if(f3!=0) (*ans)+=(f3+1);
	if(f1!=0) {
		if(f3==0&&f2==0) (*ans)+=1;
	}
	if(f2>=1) (*ans)+=1;
}
int main(void){
	//freopen("input1.txt","r",stdin);
	scanf("%d",&n);
	segment tmp;
	point test1,test2;
	double x1,y1,x2,y2;int cnt1=0,ans=1;
	tmp1.p1.x=-10;tmp1.p1.y=10;
	tmp1.p2.x=-10;tmp1.p2.y=-10;
	tmp2.p1.x=-10;tmp2.p1.y=-10;
	tmp2.p2.x=10;tmp2.p2.y=-10;
	tmp3.p1.x=10;tmp3.p1.y=-10;
	tmp3.p2.x=10;tmp3.p2.y=10;
	tmp4.p1.x=10;tmp4.p1.y=10;
	tmp4.p2.x=-10;tmp4.p2.y=10;		//given square
	for(int i=0;i<n;i++){
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		tmp.p1.x=x1;tmp.p1.y=y1;tmp.p2.x=x2;tmp.p2.y=y2;
		if(cut_square(tmp)){
			increasing_solution(cnt1,tmp,&ans);
			save[cnt1].p1.x=x1;
			save[cnt1].p1.y=y1;
			save[cnt1].p2.x=x2;
			save[cnt1++].p2.y=y2;
		}
	}
	printf("%d\n",ans);
	return 0;
}