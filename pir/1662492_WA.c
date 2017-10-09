#include<stdio.h>
int main(void)
{

int i;
		int given[20];
		int max[2];
		int kkun = -31;
		int kkkun = -31;
		int second[19];
		for (i = 0; i < 20; i++)
{
				scanf("%d", &given[i]);
}
		for (i = 0; i < 20; i++)
{
			if (given[i] > kkun)
			{
				kkun = given[i];
			}

	}
	for (i = 0; i < 20; i++)
{
			if (given[i] == kkun )
			{
				given[i]= -31;
			}
if (given[i] > kkkun)
			{
				kkkun = given[i];
			}
	}

		printf("%d\n", kkkun + kkun);
		printf("%d %d", kkun, kkkun);

		


	return 0;
}