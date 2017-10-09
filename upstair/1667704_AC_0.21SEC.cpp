#include<stdio.h>
int n ,cnt;
void upstair(int s) {
	if (s > n){
		return;
	}
	if (s == n){
		cnt++;
		return;
	}
	upstair(s + 1);
	upstair(s + 2);
}
int main() {
	scanf("%d", &n);
	upstair(0);
	printf("%d", cnt);
}