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
	int i;
	for(i=1;i*i<=L;i++) {
		if(L%i==0) {
			printf("%d %d %d\n",i,R/i,G/i);
			if(i!=L/i) printf("%d %d %d\n",L/i,R/(L/i),G/(L/i));
		}
		
	}
}