#include<stdio.h>
int main() {
	int d,h,m;
	scanf("%d%d%d",&d,&h,&m);
	//2/14/00/00
	int s1=1440*13;
	int s2=1440*(d-1)+h*60+m;
	printf("%d",s2-s1);
}