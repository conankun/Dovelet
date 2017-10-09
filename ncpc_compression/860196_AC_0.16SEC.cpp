#include<stdio.h>
int main() {
	long long a,b;
	scanf("%lld%lld",&a,&b);
	int i;
	long long c=1;
	for(i=1;i<=b+1;i++) c*=2;
	if(c-1 >= a) printf("yes");
	else printf("no");
}