#include<stdio.h>
long long n,m;
long long gcd(long long a,long long b) {
	long long c;
	do {
		c=a%b;
		a=b;
		b=c;
	}while(c!=0);
	return a;
}
long long led(long long a,long long b) {
	long long gob=a*b;
	long long c;
	do {
		c=a%b;
		a=b;
		b=c;
	}while(c!=0);
	return gob/a;
}
int main() {
	scanf("%lld%lld",&n,&m);
	long long a=-1,b=-1;
	long long g=m/n,i;
	for(i=1;i*i<=g;i++) {
		long long aa=i,bb=g/i;
		long long gc=gcd(aa*n,bb*n);
		long long le=led(aa*n,bb*n);
		if(gc == n && le == m) {
			if(a == -1 || aa+bb < a+b) {
				a=aa;
				b=bb;
			}
		}
	}
	printf("%lld %lld",a*n,b*n);
}