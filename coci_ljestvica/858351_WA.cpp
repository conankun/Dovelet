#include<stdio.h>
#include<string.h>
char s[100000];
int main() {
	scanf("%s",s);
	int i;
	int l=strlen(s);
	int c=0,a=0;
	for(i=-1;i<l;i++) {
		if(s[i]=='|'||i==-1) {
			if(s[i+1]=='A' || s[i+1]=='D' || s[i+1]=='E') a++;
			if(s[i+1]=='C' || s[i+1]=='F' || s[i+1]=='G') c++;
			i++;
		}
	}
	if(c>=a) printf("C-dur");
	else printf("A-mol");
}