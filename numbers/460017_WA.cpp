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
				if(sum > 1000) sum-=1000*((int)(sum/1000));
			}
			s=s*s;
			if(s > 1000) s-=1000*((int)(s/1000));
		}
		/*
		for(i=1;i<=n;i++) {
			sum*=s;
			if(sum > 10000) sum-=10000*((int)(sum/10000));
		}*/
		int p=(int)sum;
		printf("Case #%d: %03d",j,p%1000);
	}
}