#include <stdio.h>


int main(void)
{
	int i, j, n;
	scanf("%d %d", &n, &j);
	if (j > n){
		
		for (i = 1; i <= j; i++){
			if (n%i == 0 && j%i == 0 && i > 1 && n != j){
				printf("no");
				break;
			}
			if (n%i != 0 && j%i == 0 && i == j){
				printf("yes");
				break;
			}
		}

	}
	if (n > j){
		for (i = 1; i <= n; i++){
			if (n%i == 0 && j%i == 0 && i > 1 && n != j){
				printf("no");
				break;
			}
			if (n%i == 0 && j%i != 0 && i == n){
				printf("yes");
				break;
			}
		}

	}
	if (n == j){
		printf("no");
	}
	return 0;
}