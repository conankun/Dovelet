#include <stdio.h>
int ranked[1005];
int main()
{

	int i, j, n, k;
	int rank[1005];
	;
	scanf("%d", &n);
	for (k = 1; k <= n; k++){
		scanf("%d", &rank[k]);
	}
	for (i = 1; i<=n; i++){
		for (j = i + 1; j<=n; j++){
			if (rank[i] < rank[j]){
				ranked[i] = ranked[i]+1;
			}
			else if (rank[i] > rank[j]){
				ranked[j] = ranked[j] + 1;
			}
		}
	}

	for (i = 1; i<=n; i++){
		printf("%d \n", ranked[i]+1);
	}

	return 0;
}