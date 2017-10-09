#include<stdio.h>
int a[1000],b[100][100];
int main() {
	int i,j;
	for(i=1;i<=12;i++) {
		scanf("%d",&a[i]);	
	}
	for(i=1;i<=3;i++) {
		for(j=1;j<=4;j++) {
			printf("%d ",a[(i-1)*4+j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=1;i<=3;i++) {
		for(j=1;j<=4;j++) {
			b[i][j]=a[(i-1)*4+j];
		}
	}
	for(i=1;i<=4;i++) {
		for(j=1;j<=3;j++) {
			printf("%d ",b[j][i]);
		}
		printf("\n");
	}
}