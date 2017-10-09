#include<stdio.h>
int main() {
	int i,j;
	int aa,bb;
	int cc,dd;
	scanf("%d%d",&aa,&bb);
	{
		i=aa;
		int size=1;
		while(size <= i) size*=10;
		size/=10;
		int j=0;
		int z=i;
		while(z>0) {
			j+=(z%10)*size;
			size/=10;
			z/=10;
		}
		cc= j;
	}
	{
		i=bb;
		int size=1;
		while(size <= i) size*=10;
		size/=10;
		int j=0;
		int z=i;
		while(z>0) {
			j+=(z%10)*size;
			size/=10;
			z/=10;
		}
		dd= j;
	}
	if(cc>=dd) printf("%d",cc);
	else printf("%d",dd);

}