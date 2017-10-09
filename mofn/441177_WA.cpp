#include<stdio.h>
int main() {
	int m=0;
	char a;
	while(scanf("%c",&a) !=-1) m+=a-48;
	while(m/10 > 0) {
		int a=m;
		int s=0;
		while(a > 0) {
			s+=a%10;
			a/=10;
		}
		m = s;
	}
	printf("%d",m);
}