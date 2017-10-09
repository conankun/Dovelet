#include<stdio.h>
int isPrime[1111111];
int main() {
	int i, j;
	int n;
	scanf("%d", &n);
	for (i = 2; i <= n; i++) isPrime[i] = 1;
	for (i = 2; i <= n; i++) {
		for (j = i*2; j <= n; j += i) {
			isPrime[j] = 0;
		}
	}
	for (i = 1; i <= n; i++){
		j = n - i;
		if (isPrime[j] == 1 && isPrime[i] == 1){
			printf("%d = %d + %d", n, i, j);
			return 0;
		}
	}
	printf("Goldbach's conjecture is wrong.");
}
