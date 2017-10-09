#include<stdio.h>
#include<string.h>
int main() {
	int n;
	char s[10000];
	scanf("%d\n",&n);
	scanf("%s",s);
	int ss=strlen(s);
	int i,j;
	for(i=0;i<ss;i++) {
		for(j=1;j<=n;j++) printf("%c",s[i]);
	}
}