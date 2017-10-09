#include<stdio.h>
char binchar[1000];
int imsibin[1000];
int bin[1000];
int n;
int main() {
	int i;
	while(1) {
		if(scanf("%c",&binchar[n+1]) == -1) break;
		if(binchar[n+1] >= '0' && binchar[n+1] <= '9') n++;
	}
	int push = (n-(n%3)+3)-n;
	for(i=1;i<=push;i++) bin[i]=0;
	for(i=1;i<=n;i++) {
		bin[i+push]=binchar[i]-'0';
	}
	for(i=1;i<=n+push;i+=3) {
		int g = 1*bin[i+2]+2*bin[i+1]+4*bin[i];
		printf("%d",g);
	}
}