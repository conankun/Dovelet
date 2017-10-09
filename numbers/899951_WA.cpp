#include<stdio.h>
#include<math.h>
struct A {
    long long a,b;
};
A returns(A a,A b) {
	A c;
	c.a = a.a*b.a + 5*a.b*b.b;
	c.b = a.a*b.b + b.a * a.b;
	c.a%=1000;
	c.b%=1000;
	return c;
}
int main() {
    long long t;
    scanf("%lld",&t);
	long long i=0;
    while(t--) {
        i++;
		long long n;
        scanf("%lld",&n);
        A a;
        a.a = 3;a.b = 1;
		A b=a;
		A res;
		res.a=1;res.b=0;
		for(;n>0;n/=2) {
			if(n%2==1) {
				res=returns(res,a);
			}
			a=returns(a,a);
			
		}
		double sq = sqrt(5.)*res.b;
		long long rs = (long long)sq+res.a;
		rs%=1000;
		printf("Case #%lld: %03d\n",i,(int)rs);
    }
}