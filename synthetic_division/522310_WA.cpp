#include<stdio.h>
int k,a[999],m,b[999];
int main() {
	scanf("%d",&k);
	int i,j;
	for(i=1;i<=k+1;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	int g=a[1];
	b[1]=a[1];
	int cnt=0;
	for(i=2;i<=k+1;i++) {
		cnt++;
		g*=m;
		g+=a[i];
		b[i]=g;
	}
	for(i=1;i<=k;i++) {
		if(b[i]==0) continue;
		if(b[i]>0 && i>1) printf("+");
		if(cnt-i > 1 && b[i]==1) {printf("x^%d",cnt-i);continue;}
		else if(cnt-i==1 && b[i]==1){printf("x",cnt-i);continue;}
		if(cnt-i==1) printf("%dx",b[i]);
		else if(cnt-i > 1)printf("%dx^%d",b[i],cnt-i);
		else printf("%d",b[i]);
	}
	printf("\n%d",b[k+1]);
}