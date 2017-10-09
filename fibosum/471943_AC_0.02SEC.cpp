#include<stdio.h>
#define MOD (1000000007)
int T;
struct matrix {
	long long a,b,c,d;
};
matrix matrixprod(matrix a,matrix b) {
	matrix c;
	c.a = a.a*b.a + a.b*b.c;
	c.b = a.a*b.b + a.b*b.d;
	c.c = a.c*b.a + a.d*b.c;
	c.d = a.c*b.b + a.d*b.d;
	c.a%=MOD;
	c.b%=MOD;
	c.c%=MOD;
	c.d%=MOD;
	return c;
}
int main() {
	scanf("%d",&T);
	int i;
	for(i=1;i<=T;i++) {
		long long a,b;
		scanf("%lld%lld",&a,&b);
		a++;
		matrix ans = {1,0,0,1};
		matrix aa = {1,1,1,0};
		matrix ans2={1,0,0,1};
		matrix bb = {1,1,1,0};
		for(;a;a>>=1) {
			if(a&1) {
				ans = matrixprod(ans,aa);
			}
			aa = matrixprod(aa,aa);
		}
		b+=2;
		for(;b;b>>=1) {
			if(b&1) {
				ans2 = matrixprod(ans2,bb);
			}
			bb = matrixprod(bb,bb);
		}
		ans2.b--;
		ans.b--;
		long long outs = ((ans2.b+MOD)-ans.b)%MOD;
		printf("%lld\n",outs);
	}
}