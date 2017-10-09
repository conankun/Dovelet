#include <stdio.h>
#include <algorithm>
struct orly{
	int numbers;
}numbers[100000];
int flip_and_addaroo(int a){
	int unit = 1, i, reversed_num=0;
	while (1){
		if (a / unit < 1){
			unit /= 10;
			break;
		}
		unit *= 10;
	}
	for (i = unit; i >= 1; i /= 10){
		reversed_num = ((a % 10)*unit) + reversed_num;
		a /= 10;
		unit /= 10;
	}
	return(reversed_num + a);
}
int main(void){
	int j;
	for (j = 10; j <= 100000; j++){
		if (j == flip_and_addaroo(j)){
			printf("%d\n", j);
		}
	}
}