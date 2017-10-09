#include <stdio.h>
int prime(int a){
	int i, primee = 0;
	for (i = 2; i <= 30000; i++) {
		if (i == a){
			primee = 1;
			break;
		}
		if (a%i == 0){
			primee = 0;
			break;
		}
	}
	return primee;
}
int main(void){
	int n, i, j, qual=-1000, small, bigg, k, primee;
	scanf("%d", &n);
	primee = 0;
	for (i = 1; i < n; i ++){
		for (j = 1; j < n; j ++){
			primee = prime(i) + prime(j);
				if (i + j == n && j - i > qual&& primee == 2){
					qual = j - i;
					small = i;
					bigg = j;
				}
				primee = 0;
			}
		}
	if (small + bigg == n){
		printf("%d = %d + %d", n, small, bigg);
	}
	else {
		printf("Goldbach's conjecture is wrong.");
	}

}