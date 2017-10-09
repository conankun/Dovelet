#include<iostream>
#include<algorithm>
using namespace std;
int n;
int aray[10099];
int dyn[10099];
int btk[10099];
int bt2[10099];
int max_place = 0;
int max(int a, int b){
	if (b-a >0){
		return b;
	}
	return a;
}
int main(void){
	int i, j, k;
	cin >> n;
	int maxi = -1;
	for (i = 1; i <= n; i++){
		cin >> aray[i];
	}
	for (j = 1; j <= n; j++){
		for (k = 0; k < j; k++){
			if (aray[k]<aray[j]){
				if (dyn[j] < dyn[k] + 1){
					dyn[j] = dyn[k] + 1;
					btk[j] = k;
				}
			}
			if (dyn[j] > maxi){
				maxi = dyn[j];
				max_place = j;
			}
		}
	}
	cout << maxi << endl;
	int top = 0;
	bt2[++top] = max_place;
	while (btk[max_place] != 0) {
		bt2[++top] = btk[max_place];
		max_place = btk[max_place];
	}
	for (i = top; i >= 1; i--) {
		cout << aray[bt2[i]] << " ";
	}
}