#include<string.h>
#include<stdio.h>
char s[10000000];
int main() {
	char c;
	gets(s);
	scanf("%c",&c);
	int size=strlen(s);
	int i;
	bool tr=false;
	for(i=0;i<size;i++) {
		if(s[i]==c) {
			tr=true;
			printf("%d",i);
			break;
		}
	}
	if(!tr) printf("Not found");
}