#include<stdio.h>
int N;
char print[100][100];
int main() {
	scanf("%d",&N);
	int y=10,x=0;
	print[y][x]='*';
	while(x<=59) {
		y++,x++;
		if(y>=0&&y<=20) {
			print[y][x]='*';
		}
		if((x-N-1)%(2*N)==0) {
			int minus=2*N,i;
			for(i=0;i<=minus;i++) {
				if(y-i>=0&&y-i<=20) print[y-i][x]='*';
			}
			y=y-minus;
		}
	}
	int i,j;
	int c=10;
	for(i=20;i>=0;i--) {
		for(j=0;j<=59;j++) {
			printf("%c",print[i][j]);
		}
		printf("|%3dV",c);
		c--;
		printf("\n");
	}
}