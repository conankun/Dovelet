#include<stdio.h>
int n;
char a,b;
int main() {
	scanf("%c%c",&a,&b);
	if(b >= '0' && b <= '9') b-='0';
	else b=b-'A'+10;
	if(a >= '0' && a <= '9') a-='0';
	else a=a-'A'+10;
	int x=0;
	int s=8;
	while(b>0) {
		x+=b%2*s;
		b/=2;
		s/=2;
	}
	printf("%X",x);
	x=0;
	s=8;
	while(a>0) {
		x+=a%2*s;
		a/=2;
		s/=2;
	}
	printf("%X",x);
}
