#include <stdio.h>
int main(void) {
		int i, j, k;
		int days;
		int dduk;
		int given[20];
		int first;
		int second;
		int mid;
		scanf("%d %d", &days, &dduk);
		
		for (i = 1; i<dduk; i++)
		{

			for (j = 1; j < dduk; j++)
			{
				
				first = i;
				second = j;

				for (k = 3; k <= days; k++)
				{
					if (i == 2 && j == 7) {
						i = i;
					}
					mid = first + second;
					first = second;
					second = mid;
				}
				if (mid == dduk) {
					printf("%d\n%d", i, j);
					return 0;
				}
			}
		//	printf("%d\n", kun + kkun);
		//	printf("%d %d", kun, kkun);
		}
}