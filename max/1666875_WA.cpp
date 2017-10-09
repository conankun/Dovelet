#include <stdio.h>


int main(void)
{
	int i, j, max;
	int arr[7];
	for (i = 0; i <= 6; i++){
		scanf("%d", arr[i]);
	}
	max = arr[0];
	for (j = 0; j <= 6; j++){
		if (arr[j] > max){
			max = arr[j];
		}
	}
	printf("%d", max);
	return 0;
}