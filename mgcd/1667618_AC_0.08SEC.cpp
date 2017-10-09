#include <stdio.h>
int gcd(int a, int b){
	int c;
	do{
		c = a%b;
		a = b;
		b = c;
	} while (c != 0);
	return a;
}
int arr[101];

int main(void){
	int a, b, n, i, final2;
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	final2 = arr[1];
	for (i = 2; i <= n; i++){
		final2 = gcd(arr[i], final2);
	}
	printf("%d", final2);
	
}