#include<stdio.h>

int arr2[100][100];
//arr2[i][j]

int main(void)
{
	int i, j;
	for (i = 1; i <= 3; i++) {
		for (j = 1; j <= 4; j++){
			scanf("%d", &arr2[i][j]);
			printf("%d ", arr2[i][j]);
		}
		printf("\n");

	}
	printf("\n");
	for (i = 1; i <= 4; i++)
	{ 
		for (j = 1; j <= 3; j++){
			printf("%d ", arr2[j][i]);
		}
		printf("\n");
	}

}