#include <stdio.h>
int flip(int a){
	int unit = 1, i, reverse_num;
	while (1) {
		if (a / unit < 1) {
			unit /= 10; //unit = unit/10;
			break;
		}
		unit *= 10;
	}
	reverse_num = 0;
	for (i = unit; i >= 1; i /= 10){
		reverse_num = ((a%10)*unit) + reverse_num;
		a /= 10;
		unit /= 10;
	}
	return(reverse_num);
}
int main() {
	int x, y, summa;
	scanf("%d %d", &x, &y);
	summa = flip(x) + flip(y);
	printf("%d", flip(summa));
}