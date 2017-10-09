#include<stdio.h>
long long n,m,k,d,T;
int main() {
	long long l;
	scanf("%lld",&T);
	for(l=1;l<=T;l++) {
		scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
		if(m<0)m=m*-1;
		if((m-n)*k<=d*24) {
			printf("Case %lld: Yes\n",l);
		} else {
			printf("Case %lld: No\n",l);
		}
	}
}