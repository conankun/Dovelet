#include<stdio.h>
#include<iostream>
using namespace std;
int main() {
	for(int aaa=1;aaa<=4;aaa++) {
	int a,b,c,d;int e,f,g,h;
	int a1,a2,a3,a4;int b1,b2,b3,b4;
	scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
	a1=min(a,c);
	a2=min(b,d);
	a3=max(a,c);
	a4=max(b,d);
	b1=min(e,g);
	b2=min(f,h);
	b3=max(e,g);
	b4=max(f,h);
	if(a1==b1 && a2==b2 && a3==b3 && a4==b4) {
		printf("a\n"); return 0;
	}
	if((a4<b2 || b4<a2) || (a3<b1 || b3<a1)) {
		printf("d\n");
	} else if(b3==a1 && b4==a2) { //point
	 	printf("c\n");
	} else if(b1==a3 && b4==a2) {
		printf("c\n");
	} else if((b3==a1 && b2==a4)) {
		printf("c\n");
	} else if((a3==b1 && a4==b2)) {
		printf("c\n");
	} else if((b1<a3 && b4==a2) || (b2<a4 && a3==b1) || (b3==a1 && b2 < a4) || (b2==a4 && b1<a3)) {
		printf("b\n");
	}  else {//none 
		printf("a\n");
	}
	}
}