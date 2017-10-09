#include <stdio.h>


int main(void)
{
	int start, i, x, ans, cursor;
	
	scanf("%d %d %d", &start, &x, &ans);
	
	for (i = 1; i <= 99999999; i++){
		cursor = start + x*i;

		if (cursor == ans){
			printf("%d", i);
			break;
		}
		if (x < 0 && cursor < ans){
			printf("X");
			break;

		}
		if (x>0 && cursor > ans){
			printf("X");
			break;
		}

	}
	return 0;
}