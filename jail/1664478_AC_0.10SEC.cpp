#include<stdio.h>
int arr[111111];
int n;
int count=1;
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
	{
		if (arr[i] == 0)
		{
			count++;
			for (j = i; j <= n; j += i)
			{
				arr[j] = 1 - arr[j];
			}
		}
	}
	printf("%d", count);
	return 0;
}