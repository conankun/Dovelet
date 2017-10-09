#include<stdio.h>
#include<string.h>
char s[1000000];
int main() {
	scanf("%s",s);
	int i;
	int size=strlen(s);
	for(i=0;i<size;i++) {
		if(i==0 || s[i-1]=='-') {
			printf("%c",s[i]);
		}
	}
}