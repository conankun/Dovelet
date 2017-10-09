#include <stdio.h>
int main(void) {
	int n, i;
	int mid;
	int first=2;
	int second= 3 ;
	

	scanf("%d", &n);
	for (i = 3; i <= n; i++)
	{
		mid = first + second;
		first = second;
		second = mid;
	}
	if (n == 1)
		printf("2");
	else if (n == 2)
		printf("3");
	else printf("%d", mid);
}