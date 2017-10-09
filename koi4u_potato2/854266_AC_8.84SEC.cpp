#include<stdio.h>
double a[1111111][3];//x,y,w
int n;
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%lf%lf%lf",&a[i][0],&a[i][1],&a[i][2]);
	double sumwk=0,sumxw=0,sumyw=0;
	for(i=1;i<=n;i++) {
		sumwk+=a[i][2];
		sumxw+=(a[i][0]*a[i][2]);
		sumyw+=(a[i][1]*a[i][2]);
	}
	printf("%.3lf %.3lf",sumxw/sumwk,sumyw/sumwk);
}