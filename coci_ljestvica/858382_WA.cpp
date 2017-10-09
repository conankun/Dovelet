#include<stdio.h>
#include<string.h>
char s[100000];
int main() {
	scanf("%s",s);
	int i;
	int l=strlen(s);
	double c=0,a=0;
	int lastone=0;
	for(i=0;i<l;i++) {
		if(s[i]=='|'||i==0) {
			if(s[i]=='|') i++;
			if(s[i]=='A' || s[i]=='D' || s[i]=='E') {a+=1;lastone=1;}
			if(s[i]=='C' || s[i]=='F' || s[i]=='G') {c+=1;lastone=0;}
		}
	}
	if(c>a) printf("C-dur");
	else if(c==a) {
		if(lastone==1) printf("A-mol");
		else printf("C-dur");
	}
	else printf("A-mol");
}