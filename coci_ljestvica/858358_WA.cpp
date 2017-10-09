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
			int cnts=0;
			for(;i<l;i++) {
				cnts++;
				if(cnts==1 || cnts==4 || cnts==5) if(s[i]=='A' || s[i]=='D' || s[i]=='E') a++;
				if(cnts==1 || cnts==4 || cnts==5) if(s[i]=='C' || s[i]=='F' || s[i]=='G') c++;
				if(s[i+1]=='|') break;
			}
		}
	}
	if(c>=a) printf("C-dur");
	else printf("A-mol");
}