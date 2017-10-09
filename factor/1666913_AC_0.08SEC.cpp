#include <stdio.h>


int main(void)
{
	int given, i;
	
	scanf("%d", &given);
	
	for (i = 1; i <= given; i++){
		if (given%i == 0)
			printf("%d\n", i);
	}


	return 0;
}