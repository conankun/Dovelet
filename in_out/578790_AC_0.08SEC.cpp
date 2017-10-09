#include<stdio.h>
int a,b,c,d,e;
struct A {
	int x,y;
}x,y,z,w;
struct E {
	int a,b;//a기울기 b절편
};
bool tr=1;
int main() {
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	x.x = a;
	x.y = b+c;
	y.x = a-c;
	y.y = b;
	z.x = a;
	z.y = b-c;
	w.x = a+c;
	w.y = b;
	//(x,y)
	E ee;
	ee.a = (y.y-x.y)/(y.x-x.x);
	ee.b = y.y-(y.x*ee.a);
	if(ee.a*d + ee.b < e) tr=0;
	//(y,z)
	ee.a = (y.y-z.y)/(y.x-z.x);
	ee.b = y.y-(y.x*ee.a);
	if(ee.a*d + ee.b > e) tr=0;
	//(z,w)
	ee.a = (z.y-w.y)/(z.x-w.x);
	ee.b = z.y-(z.x*ee.a);
	if(ee.a*d + ee.b > e) tr=0;
	//(w,x)
	ee.a = (w.y-x.y)/(w.x-x.x);
	ee.b = w.y-(w.x*ee.a);
	if(ee.a*d + ee.b < e) tr=0;
	if(tr) printf("yes");
	else printf("no");
}