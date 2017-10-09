#include<stdio.h>
int GCD(int a,int b) {
	int c;
	do {
		c=a%b;
		a=b;
		b=c;
	}while(c!=0);
	return a;
}
int R,G;
int main() {
	scanf("%d%d",&R,&G);
	int L=GCD(R,G);
	int i,mode=0;
	for(i=1;;mode==0?i++:i--) {
		if(L%i==0&&mode==0) {
			printf("%d %d %d\n",i,R/i,G/i);
		}
		else if(L%i==0&&mode==1) {
				printf("%d %d %d\n",L/i,R/(L/i),G/(L/i));
		}
		if(i*i>=L) {
			mode=1;
		}
		if(mode==1 && i==1) break;
	}
}