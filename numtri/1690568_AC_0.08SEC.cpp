#include <iostream>
#include <algorithm>
using namespace std;
int field[1111][1111];
int dyn[1111][1111];
int maxo = 0;
int place=0;
int max(int a, int b){
	if (b - a > 0){
		return b;
	}
	return a;
}
int main(void){
	int n,i,j;
	cin >> n;
	for (i = 1; i <= n; i++){
		for (j = 1; j <= i; j++){
			cin >> field[i][j];
		}
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= i; j++){
			dyn[i][j] = max(dyn[i-1][j - 1], dyn[i - 1][j]) +field[i][j];
		}
	}
	for (i = 1; i <= n; i++){
		if (dyn[n][i] > maxo){
			maxo = dyn[n][i];
			place = i;
		}
	}
	cout << dyn[n][place];
}