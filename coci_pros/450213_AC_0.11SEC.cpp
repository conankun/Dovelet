#include<stdio.h>
#include<string.h>
char s[100];
int c[6];
int p=0,g=1,o=0,g2=1,log=-1;
int gcd(int a,int b) {
	int c;
	do {
		c=a%b;
		a=b;
		b=c;
	}while(c!=0);
	return a;
}
int min(int a,int b) {
	if(a<b) return a;
	return b;
}
int main() {
	scanf("%s",s);
	int pivot;
	int i;
	for(i=strlen(s)-1;i>=0;i--) {
		if(s[i] == '.') {
			pivot=i;
			break;
		} else {
			p+=(s[i]-48)*g;
			g*=10;
		}
	}
	for(i=pivot-1;i>=0;i--) {
		o+=(s[i]-48)*g2;
		g2*=10;
	}
	int div = g/gcd(p,g);
	int hap = o*(g/gcd(p,g))+p/gcd(p,g);
	c[5]=hap/5;
	c[hap%5]=1;
	int s=div-(hap/5+(hap%5==0?0:1));
	while(s>0) {
		for(i=5;i>=2;i--) {
			if(s==0) break;
			int minus=min(s,c[i]);
			c[i]-=minus;
			c[1]+=minus;
			c[i-1]+=minus;
			s-=minus;
		}
	}
	for(i=1;i<=5;i++) printf("%d ",c[i]);
}
