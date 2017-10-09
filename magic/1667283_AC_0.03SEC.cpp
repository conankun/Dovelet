#include <stdio.h>

int magic[32][32];
int main(void)
{ 
	int i, j, n, k, l, g;
	int mid;
	scanf("%d", &n);
	mid = (n / 2) + 1;
	g = 2;
	magic[1][mid] = 1;
	j = mid + 1;
	
	for (i = 0; i <= n; i--){


		if (i < 1){
			i = n;
		}
		if (j > n){
			j = 1;
		}
		magic[i][j] = g;

		if (magic[i][j] % n == 0){
			j = j - 1;
			i = i + 2;
		}
		g = g + 1;
		j = j++;
		if (g > n*n){
			break;
		}
	}
		
	
		for (k = 1; k <= n; k++){
		for (l = 1; l <= n; l++){
			printf("%3d", magic[k][l]);
			if (l == n){
				l = 1;
				printf("\n");
				break;
			}
			
			
		}
		if (k > n){
			break;
		}
	}
	return 0;
}
