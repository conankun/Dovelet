#include<stdio.h>
int n;
int main() {
	scanf("%d",&n);
	int x=1;
	for(;x<=n;x*=16);
	x/=16;
	int S=0;
	while(n>0) {
		int m=n%10;
		int s=8;
		int k=0;
		while(m>0) {
			k+=m%2*s;
			s/=2;
			m/=2;
		}
		S+=k*x;
		x/=16;
		n/=10;
	}
	printf("%X",S);
}
