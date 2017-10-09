#include<stdio.h>
#include<stdlib.h>
int m[10][10],i,j,tr=1;
int main() {
	for(i=1;i<=5;i++) {
		for(j=1;j<=5;j++) {
			scanf("%d",&m[i][j]);
		}
	}
	for(i=1;i<=5;i++) {
		int a,s=0;;
		for(j=1;j<=5;j++) {
			if(i==j) a=m[i][j];
			else s+=abs(m[i][j]);
		}
		if(abs(a) < s) tr=0;
	}
	if(tr) printf("yes");
	else printf("no");
}