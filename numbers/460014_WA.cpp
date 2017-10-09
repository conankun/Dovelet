#include<stdio.h>
#include<math.h>
double s,ss;
int n,m;
double sum=1.00;
int main() {
	scanf("%d",&m);
	int i,j;
	for(j=1;j<=m;j++) {
		s=3+sqrt(5);
		scanf("%d",&n);
		sum=1.00;
		for(;n;n>>=1) {
			if(n&1) {
				sum*=s;
			}
			s=s*s;
			if(sum > 10000) sum-=10000*((int)(sum/10000));
			if(s > 10000) s-=10000*((int)(s/10000));
		}
		int p=(int)sum;
		printf("Case #%d: %03d",j,p%1000);
	}
}