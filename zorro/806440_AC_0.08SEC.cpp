#include<stdio.h>
int main()
{
	int i,j,n,l;

	scanf("%d",&n);
	l = n-2;

	

	for(i=0;i<n;i++)
	{
		printf("*");
	}
	printf("\n");
	for(i=0;i<n-2;i++)
	{
		for(j=0;j<l;j++)
		{
			printf(" ");
		}
		printf("*\n");
		l--;
	}
	for(i=0;i<n;i++)
	{
		printf("*");
	}

	return 0;
}