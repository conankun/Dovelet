#include<stdio.h>
int h,m,s;
int d;
int main() {
	scanf("%d%d%d%d",&h,&m,&s,&d);
	int i;
	for(i=1;i<=d;i++) {
		s++;
		if(s>=60) {
			s-=60;m+=1;
		}
		if(m >= 60) {
			m-=60;h++;
		}
		if(h>=24) {
			h-=24;
		}
	}
	printf("%d %d %d",h,m,s);
}