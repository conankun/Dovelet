#include<stdio.h>
int a[22];
int b[22];
int p[2];
int main() {
	int i;
	for(i=1;i<=10;i++) scanf("%d",&a[i]);
	for(i=1;i<=10;i++) scanf("%d",&b[i]);
	for(i=1;i<=10;i++) {
		if(a[i] > b[i]) p[0]+=3;
		else if(a[i] < b[i]) p[1]+=3;
		else { p[0]++;p[1]++; }
	}
	printf("%d %d\n",p[0],p[1]);
	if(p[0] > p[1]) printf("A");
	else if(p[1] > p[0]) printf("B");
	else {
		if(a[10]==b[10]) printf("D");
		else if(a[10] > b[10]) printf("A");
		else printf("B");
	}
}