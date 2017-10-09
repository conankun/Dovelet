#include <stdio.h>


int main(void)
{
	int i, j, n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		if (n%i == 0 && i > 1 && i != n){
			printf("not prime");
			break;
		}
		if (n%i == 0 && i == n){
			printf("prime");
			break;
		}
	}
	return 0;
}