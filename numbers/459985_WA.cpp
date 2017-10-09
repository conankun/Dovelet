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
			if(sum > 1000) sum-=1000;
			if(s > 1000) s-=1000;
		}
		int p=(int)sum;
		printf("case #%d: %03d\n",j,p%1000);
	}
}