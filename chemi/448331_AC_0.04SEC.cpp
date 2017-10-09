#include<stdio.h>
#include<string.h>
char s[10000];
int main() {
	gets(s);
	int len = strlen(s);
	int i;
	for(i=0;i<len;i++) {
		if(s[i] =='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {
			if(s[i+2]==s[i] && s[i+1] == 'p') {
				printf("%c",s[i]);
				i+=2;
				continue;
			} else {
				printf("%c",s[i]);
			}
		} else {
			printf("%c",s[i]);
		}
	}
}
