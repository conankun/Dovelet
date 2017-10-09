#include<stdio.h>
int M;
int map[100][100];
int map2[100][100];
char c[100][100];
int main() {
	scanf("%d",&M);
	int i,j,k,l;
	for(i=1;i<=8;i++) {
		for(j=1;j<=8;j++) {
			scanf("%d",&map[i][j]);
		}
	}
	for(i=1;i<=8;i++) {
		for(j=1;j<=8;j++) {
			map2[i][j]=M;
			int lm=0;
			for(k=1;k<=8;k++) lm+=map[i][k];
			for(k=1;k<=8;k++) lm+=map[k][j];
			lm-=map[i][j];
			if(lm%2!=M%2) {
				c[i][j]='-';
			}
		}
	}
	for(i=1;i<=8;i++) {
		for(j=1;j<=8;j++) {	
			if(c[i][j]=='-') {
				for(k=1;k<=8;k++) map2[i][k]--;
				for(k=1;k<=8;k++) map2[k][j]--;
				map2[i][j]++;
			}
		}
	}
	for(i=1;i<=8;i++) {
		for(j=1;j<=8;j++) {
			int lm=0,ll=0;
			for(k=1;k<=8;k++) {lm+=map[i][k];ll+=map2[i][k];}
			for(k=1;k<=8;k++) {lm+=map[k][j];ll+=map2[k][j];}
			lm-=map[i][j];ll-=map2[i][j];
			if(lm%4!=ll%4 && c[i][j]=='-') {
				c[i][j]='+';
			}
		}
	}
	for(i=1;i<=8;i++) {
		for(j=1;j<=8;j++) {
			if(c[i][j]==0) c[i][j]='.';
			printf("%c ",c[i][j]);
		}
		printf("\n");
	}
}