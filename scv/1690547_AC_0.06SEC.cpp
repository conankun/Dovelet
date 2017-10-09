#include <iostream>
#include <algorithm>
using namespace std;
int field[111][111];
int dyn[111][111];
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
		for (j = 1; j <= n; j++){
			cin >> field[i][j];
		}
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			dyn[i][j] = max(dyn[i][j - 1], dyn[i - 1][j]) +field[i][j];
		}
	}
	cout << dyn[n][n];
}