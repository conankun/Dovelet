#include<stdio.h>
#include<string.h>
char s[100000];
int main() {
	scanf("%s",s);
	int i;
	int l=strlen(s);
	double c=0,a=0;
	for(i=0;i<l;i++) {
		if(s[i]=='|'||i==0) {
			int cnts=0;
			if(s[i]=='|') i++;
			for(;i<l;i++) {
				cnts++;
				if(cnts==1) {
					if(s[i]=='A' || s[i]=='D' || s[i]=='E') a+=1;
					if(s[i]=='C' || s[i]=='E' || s[i]=='F') c+=1;
				} else if(cnts==3) {
					if(s[i]=='A' || s[i]=='D' || s[i]=='E') a+=3.5;
					if(s[i]=='C' || s[i]=='E' || s[i]=='F') c+=3.5;
				}
				if(s[i+1]=='|') break;
			}
		}
	}
	if(c>=a) printf("C-dur");
	else printf("A-mol");
}