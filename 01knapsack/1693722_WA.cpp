#include<algorithm>
#include<iostream>
using namespace std;
int max(int a, int b){
	if (b - a > 0){
		return b;
	}
	return a;
}
int arr[500];
int dyn[200][11111];
int bag;
int gemweight[200];
int gemvalue[200];
int main(){
	dyn[0][0] = 0;
	int i, j, n;
	cin >> bag;
	cin >> n;
	for (i = 1; i <= n; i++){
		cin >> gemweight[i]>>gemvalue[i];
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= bag; j++){
			if (j - gemweight[i] >= 0) {
				dyn[i][j] = max(max(dyn[i - 1][j - gemweight[i]] + gemvalue[i], max(dyn[i - 1][j], dyn[i][j - 1])), dyn[i][j]);
			}
		}
	}

	cout <<dyn[n][bag];
}