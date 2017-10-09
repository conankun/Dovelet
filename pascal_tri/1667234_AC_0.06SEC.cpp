#include <stdio.h>

int arr[32][32];
int main(void)
{ 
	int i, j, n;
	scanf("%d", &n);
	arr[1][1] = 1;
	printf("%d \n", arr[1][1]);
	for (i = 2; i <= n; i++){
		for (j = 1; j <= n; j++){
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			if (arr[i][j] > 0){
				printf("%d ", arr[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}