#include<stdio.h>
#include<math.h>
int n;
struct A {
	int a,b;//front
	int c,d;//back
}page[1111];
int main() {
	scanf("%d",&n);
	int pages = ceil(n/4.00);
	int i;
	int cnt=0;
	for(i=1;i<=2*pages;i+=2) {
		page[++cnt].b = i;
		page[cnt].c = i+1;
	}
	cnt++;
	for(i=2*pages+1;i<=4*pages;i+=2) {
		page[--cnt].d = i;
		page[cnt].a = i+1;
	}
	printf("Printing order for %d pages:\n",n);
	for(i=1;i<=pages;i++) {
		char a[100],b[100],c[100],d[100];
		if(page[i].a>n) sprintf(a,"Blank");
		else sprintf(a,"%d",page[i].a);
		if(page[i].b>n) sprintf(b,"Blank");
		else sprintf(b,"%d",page[i].b);
		if(page[i].c>n) sprintf(c,"Blank");
		else sprintf(c,"%d",page[i].c);
		if(page[i].d>n) sprintf(d,"Blank");
		else sprintf(d,"%d",page[i].d);
		printf("Sheet %d, front: %s, %s\n",i,a,b);
		printf("Sheet %d, back : %s, %s\n",i,c,d);
	}
}