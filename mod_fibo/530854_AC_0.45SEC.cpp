#include<stdio.h>
long long MOD[100];
struct Matrix {
	long long a,b,c,d;
};
Matrix MatrixProd(Matrix a,Matrix b,long long mod){ 
	Matrix c;
	c.a = a.a*b.a+a.b*b.c;
	c.b = a.a*b.b+a.b*b.d;
	c.c = a.c*b.a+a.d*b.c;
	c.d = a.c*b.b+a.d*b.d;
	c.a%=MOD[mod];
	c.b%=MOD[mod];
	c.c%=MOD[mod];
	c.d%=MOD[mod];
	return c;
};
int main() {
	long long N,M,i,g=1;
	for(i=0;i<=20;i++) {
		MOD[i]=g;
		g*=2;
	}
	while(scanf("%lld%lld",&N,&M) != -1) {
		Matrix ans={1,0,0,1},G={1,1,1,0};
		for(;N;N>>=1) {
			if(N&1) {
				ans=MatrixProd(ans,G,M);
			}
			G=MatrixProd(G,G,M);
		}
		 printf("%lld\n",ans.b);
	}
}