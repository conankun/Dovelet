#include<stdio.h>
int main() {
	double a,b,c;
	while(scanf("%lf%lf%lf",&a,&b,&c) != -1) {
		if(a==1) {
			if(b<=c) printf("-1\n");
			else printf("%.2lf\n",c*(b/(b-c)));
		} else if(a==0) {
			printf("%.2lf\n",c*c/b*(b/(b+c)));
		}
	}
}