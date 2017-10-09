#include <stdio.h>
int main(void){
	long long int c, p, y, gop;
	scanf("%lld %lld", &p, &y);
	gop = p*y;
	do{
		c = p%y;
		p = y;
		y = c;
	} while (c != 0);
	
		//int a = 3, b = 5; -> int a=5, b=3;
		/*
			c = a;
			a=b;
			b=c;
		*/
	printf("%lld %lld", p, gop / p);
	return 0;
	

}