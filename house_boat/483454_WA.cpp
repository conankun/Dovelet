#include<stdio.h>
#include<math.h>
double max(double aa,double bb) {
	if(aa<bb) return bb;
	return aa;
}
double x,y;
int main() {
	scanf("%lf%lf",&x,&y);
	int i;
	double xx=0;
	for(i=1;;i++) {
		double r = sqrt((2*(50+xx))/(6*asin(.5)));
		if(r>=max(x,y)) {
			printf("Property: This property will begin eroding in year %d.",i);
			break;
		}
		xx+=50;
	}
}