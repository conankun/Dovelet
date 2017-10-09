#include<stdio.h>
int n;
int magic[100][100];
int main() {
	scanf("%d",&n);
	int a=1,b=n/2+1;
	int i,j;
	for(i=1;i<=n*n;i++) {
		magic[a][b]=i;
		if(i%n==0) {
			if(a==n) {
				a=1;
			} else a++;	
		} else {
			if(a==1) {
				a=n;
			} else a--;
			if(b==n) {
				b=1;
			} else b++;
		}
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			printf("%3d",magic[i][j]);
		}
		printf("\n");
	}
}