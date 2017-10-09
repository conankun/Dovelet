#include<stdio.h>
int main() {
	long long int m;
	long long int a;
while(scanf("%lld",&a) !=-1) m+=a;
	while(m/10 > 0) {
		long long int a=m;
		long long int s=0;
		while(a > 0) {
			s+=a%10;
			a/=10;
		}
		m = s;
	}
	printf("%d",m);
}