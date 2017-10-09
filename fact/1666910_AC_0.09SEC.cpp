#include <stdio.h>


int main(void)
{
	int given, i;
	int max = 1;
	scanf("%d", &given);
	
	for (i = 1; i <= given; i++){
		max = max * i;
	}
	printf("%d", max);


	return 0;
}