#include <stdio.h>
int spiral[100][100];
int main()
{
	int n, number=0,i,s,j,k;
	scanf("%d", &n);
	number = 0;
	s = 0;
	while (number <= n*n){
		s++;
		for (i = 1; i <= n; i++){
			if (spiral[s][i] == 0){
				number++;
				spiral[s][i] = number;
			}
		}
		for (i = 1; i <= n; i++){
			if (spiral[i][n - s+1] == 0){
				number++;
				spiral[i][n - s+1] = number;
			}
		}
		for (i = n; i >= 1; i--){
			if (spiral[n - s+1][i] == 0){
				number++;
				spiral[n - s+1][i] = number;
			}
		}

		for (i = n; i >= 1; i--){
			if (spiral[i][s] == 0){
				number++;
				spiral[i][s] = number;
			}
		}
	}
	for (j = 1; j <= n;j++){
		for (k = 1; k <= n; k++){
			printf("%5d", spiral[j][k]);
		}
		printf("\n");
	}


}
