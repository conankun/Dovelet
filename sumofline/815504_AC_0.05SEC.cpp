#include<stdio.h>
int n;
int main() {
	int a,sum=0;
	char b;
	scanf("%d",&n);
	while(scanf("%d%c",&a,&b)!=EOF) {
		sum+=a;
		if(b=='\n') {
			printf("%d\n",sum);
			sum=0;
		}
	}
}