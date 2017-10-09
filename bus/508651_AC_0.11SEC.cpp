#include<stdio.h>
int main() {
	int a;
	int b,c;
	while(scanf("%d%d%d",&a,&b,&c) != -1) {
		int d;
		if(b<c&&a==1) {
			d=b;
			b=c;
			c=d;
		}
		if(a==1) {
			if(b==c) printf("-1\n");
			else printf("%.2lf\n",c*b/(double)(b-c));
		} else if(a==0) {
			printf("%.2lf\n",c*b/(double)(b+c));
		}
	}
}