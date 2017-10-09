#include<stdio.h>
int main() {
	long long T;
	long long n,m;
	scanf("%lld",&T);
	long long i;
	for(i=1;i<=T;i++) {
		scanf("%lld%lld",&n,&m);
		long long a = n+1,b=m+1;
		long long s1=0,s2=0;
		if(a%2==0){
			s1+=a/2;
			s1%=1000;
			s1*=(n%1000);
			s1%=1000;
		} else {
			s1+=n/2;
			s1%=1000;
			s1*=(a%1000);
			s1%=1000;
		}
		if(b%2==0){
			s2+=b/2;
			s2%=1000;
			s2*=(m%1000);
			s2%=1000;
		} else {
			s2+=m/2;
			s2%=1000;
			s2*=(b%1000);
			s2%=1000;
		}
		long long sum = s1*s2;
		sum%=1000;
		printf("%lld\n",sum);
	}
}