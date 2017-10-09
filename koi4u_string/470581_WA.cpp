#include<stdio.h>
struct A {
	int a,b;
	int c,d;
};
int n;
//3 3
A root;
A ans;
void gob() {
	A imsi=root;
	A imsi2 = ans;
	ans.a = imsi.a*imsi2.a+imsi.b*imsi2.c;
	ans.b = imsi.a*imsi2.b+imsi.b*imsi2.d;
	ans.c = imsi.c*imsi2.a+imsi.d*imsi2.c;
	ans.d = imsi.c*imsi2.b+imsi.d*imsi2.d;
}
void gob2() {
	A imsi=root;
	root.a = imsi.a*imsi.a+imsi.b*imsi.c;
	root.b = imsi.a*imsi.b+imsi.b*imsi.d;
	root.c = imsi.c*imsi.a+imsi.d*imsi.c;
	root.d = imsi.c*imsi.b+imsi.d*imsi.d;
}
int main() {
	scanf("%d",&n);	
	root.a = 1;
	root.b = 1;
	root.c = 1;
	root.d = 0;
	ans.a=1,ans.b=0,ans.c=0,ans.d=1;
	n++;
	for(;n;n>>=1) {
		if(n&1) {
			gob();
			ans.a%=1000000009;
			ans.b%=1000000009;
			ans.c%=1000000009;
			ans.d%=1000000009;
		}
		gob2();
		root.a%=1000000009;
		root.b%=1000000009;
		root.c%=1000000009;
		root.d%=1000000009;
	}
	printf("%d",ans.b*2);
}