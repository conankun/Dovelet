#include<iostream>
#include<algorithm>
using namespace std;
int calories[100];
int lim, n;
int mx = 0;
void bt(int n2, int sum) {
	if (sum > lim) {
		return;
	}
	if (mx < sum) {
		mx = sum;
	}
	if (n2 == n + 1) {
		return;
	}

	bt(n2 + 1, sum + calories[n2]);
	bt(n2 + 1, sum);
}
int main(void){
	int i;
	scanf("%d %d", &lim, &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &calories[i]);
	}
	bt(1, 0);
	printf("%d", mx);
}