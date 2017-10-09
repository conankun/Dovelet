#include<stdio.h>
int n;
int chk[1000000];
int main() {
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++) {
		int a,b,c,d;
		scanf("%d:%d-%d:%d",&a,&b,&c,&d);
		int x=a*60+b;
		int y=c*60+d-1;
		for(j=x;j<=y;j++) chk[j]++;
	}
	for(i=1;i<=24*60;i++) {
		if(chk[i] > 1) {
			printf("conflict");
			return 0;
		}
	}
	printf("no conflict");
}