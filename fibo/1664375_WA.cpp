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
	printf("%d", mid);
}