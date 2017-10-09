

#include <stdio.h>
int main(void)
	{
int i;
		int rules[6] = { 1, 1, 2, 2, 2, 8 };
		int hyunshil[6];
		int need[6];
		for (i = 0; i < 6; i++)
			scanf("%d", &hyunshil[i]);
		for (i = 0; i < 6; i++)
		{
			need[i] = rules[i] - hyunshil[i];
				printf("%d ", need[i]);
		}
		return 0;
}