#include<stdio.h>
#include<math.h>
double r;
int main() {
	scanf("%lf",&r);
	long long i;
	long long sum=0;
	for(i=1;i<=r;i++) {
		double c = sqrt((r*r)-(i*i));
		long long d = (long long)c;
		sum+=(d*2+1);
	}
	sum*=2;
	sum+=2*r+1;//x=0
	printf("%lld",sum);
}
