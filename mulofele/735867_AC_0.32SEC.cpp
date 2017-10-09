#include<stdio.h>
int main() {
	int sum=0,t=0;
	char c;
	while(scanf("%c",&c)) {
		if(c<'0' || c > '9')break;
		if(t==0) sum+=(c-48);
		else sum-=(c-48);
		t++; t%=2;
	}
	if(sum%11==0) printf("yes");
	else printf("no");
}