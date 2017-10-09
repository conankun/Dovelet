#include<stdio.h>
#include<string.h>
char s1[1000000];
char s2[1000000];
int main() {
	scanf("%s\n%s",s1,s2);
	if(strlen(s1) >= strlen(s2)) printf("go");
	else printf("no");
}