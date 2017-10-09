#include<stdio.h>
int N;
char print[100][100];
int main() {
	scanf("%d",&N);
	int y=10,x=0;
	print[y][x]='*';
	int i,j;
	for(i=0;i<=59;i++) for(j=1;j<=59;j++) print[i][j]=' ';
	int cnt=1;
	while(x<=59) {
		y++,x++;
		if(y>=0&&y<=20) {
			print[y][x]='*';
		}
		cnt++;
		if((x==N && cnt==N+1) || (x>N && cnt==2*N+1)) {
			int minus=2*N,i;
			for(i=0;i<=minus;i++) {
				if(y-i>=0&&y-i<=20) print[y-i][x]='*';
			}
			y=y-minus;
			cnt=1;
		}
	}
	int c=10;
	for(i=20;i>=0;i--) {
		for(j=0;j<=59;j++) {
			if(print[i][j]=='*') printf("*");
			else printf(" ");
		}
		printf("|%3dV",c);
		c--;
		printf("\n");
	}
}