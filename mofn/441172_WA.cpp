#include<stdio.h>
int main() {
	long long int m;
	char a;
while(scanf("%c",&a) !=-1) m+=a-48;
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