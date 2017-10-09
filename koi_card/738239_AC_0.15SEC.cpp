#include<stdio.h>
int a[22];
int b[22];
int p[2];
int main() {
	int i;
	for(i=1;i<=10;i++) scanf("%d",&a[i]);
	for(i=1;i<=10;i++) scanf("%d",&b[i]);
	int pp=-1;
	for(i=1;i<=10;i++) {
		if(a[i] > b[i]) {pp=0;p[0]+=3;}
		else if(a[i] < b[i]) {pp=1;p[1]+=3;}
		else {p[0]++;p[1]++; }
	}
	printf("%d %d\n",p[0],p[1]);
	if(p[0] > p[1]) printf("A");
	else if(p[1] > p[0]) printf("B");
	else {if(pp==0) printf("A");
		else if(pp==1) printf("B");
		else printf("D");
	}
}