#include<stdio.h>
int mod[43];
int main() {
	int i,m,s=0;
	for(i=1;i<=10;i++) {
		scanf("%d",&m);
		mod[m%42]=1;
	}
	for(i=0;i<42;i++) s+=mod[i];
	printf("%d",s);	
}