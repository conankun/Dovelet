#include<stdio.h>
int M,K;
int map[100][100];
char c[100][100];
int main() {
	scanf("%d%d",&M,&K);
	int i,j,k,l;
	for(i=1;i<=8;i++) {
		for(j=1;j<=8;j++) {
			scanf("%d",&map[i][j]);
		}
	}
	for(i=1;i<=8;i++) {
		for(j=1;j<=8;j++) {
			int lm=0;
			for(k=1;k<=8;k++) lm+=map[i][k];
			for(k=1;k<=8;k++) lm+=map[k][j];
			lm-=map[i][j];
			if(lm%2!=M%2) {
				if(lm > M*15) {
					c[i][j]='+';
				} else if(lm < M*15) {
					c[i][j]='-';
				}
			}
		}
	}
	for(i=1;i<=8;i++) {
		for(j=1;j<=8;j++) {
			if(c[i][j]==0) c[i][j]='.';
			printf("%c",c[i][j]);
		}
		printf("\n");
	}
}