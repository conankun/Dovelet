#include<stdio.h>
int p[10000],n,m[10000];
int lcd(int a,int b) {
	int c;
	int g=a*b;
	do {
	c=a%b;
	a=b;
	b=c;
	} while(c!=0);
	return g/a;
}
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	for(i=1;i<=n;i++) {
		j=p[i];
		m[i]=1;
		while(j!=i) {
			j=p[j];m[i]++;
			if(i==j) break;
		}
	}
	int l=lcd(m[1],m[2]);
	for(i=3;i<=n;i++) {
		l=lcd(l,m[i]);
	}
	printf("%d",l);
}