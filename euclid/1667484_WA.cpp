#include <stdio.h>
int main(void){
	int c, p, y, gop;
	scanf("%d %d", &p, &y);
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
	printf("%d %d", p, gop / p);
	return 0;
	

}