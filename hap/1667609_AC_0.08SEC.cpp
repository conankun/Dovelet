#include <stdio.h>
int hap(int a, int b, int c, int d){
	
	return (a+b+c+d);
}


int main(void){
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("%d", hap(a, b, c, d));
	
}