#include<stdio.h>
#define MOD 1000000007
struct Matrix{ 
	long long a,b;
	long long c,d;
};
Matrix multiply(Matrix object1,Matrix object2) {
	Matrix newmat={0};
	newmat.a = object1.a*object2.a+object1.b*object2.c;
	newmat.a%=MOD;
	newmat.b = object1.a*object2.b+object1.b*object2.d;
	newmat.b%=MOD;
	newmat.c = object1.c*object2.a+object1.d*object2.c;
	newmat.c%=MOD;
	newmat.d = object1.c*object2.b+object1.d*object2.d;
	newmat.d%=MOD;
	return newmat; 
}
Matrix multiply_process(Matrix objects,long long N) {
	Matrix subject={0};
	subject.a=1;
	subject.d=1;
	for(;N>=1;N/=2) {
		long long mod_=N%2;
		if(mod_==1) {
			subject=multiply(objects,subject);
		}
		objects=multiply(objects,objects);
	}
	return subject;
}
int main() {
	long long T,f1,f2,N;
	scanf("%lld",&T);
	long long i,j;
	while(T--) {
		scanf("%lld%lld%lld",&f1,&f2,&N);
		if(f1 > f2) {
			long long tmp=f2;
			f2=f1;
			f1=tmp;
		}
		long long dif = (f2-f1)%MOD;
		f1%=MOD;
		f2%=MOD;
		Matrix fone;
		fone.a=1;
		fone.b=1;
		fone.c=1;
		fone.d=0;
		Matrix result = multiply_process(fone,N-2);
		long long ff = f1*result.b+f2*result.a;
		ff%=MOD;
		long long ff_1 = f1*result.d+f2*result.b;
		ff_1%=MOD;
		long long res = ff*(ff+ff_1)-f1*(f2-f1);
		res+=MOD;
		res%=MOD;
		printf("%lld\n",res);
	}
}