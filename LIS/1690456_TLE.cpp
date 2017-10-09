#include<iostream>
#include<algorithm>
using namespace std;
long long n;
long long aray[555555];
long long dyn[555555];
long long btk[555555];
long long bt2[555555];
long long max_place = 0;
long long max(long long a, long long b){
	if (b-a >0){
		return b;
	}
	return a;
}
int main(void){
	int i, j, k;
	cin >> n;
	long long maxi = -1;
	for (i = 1; i <= n; i++){
		cin >> aray[i];
		btk[i] = 2147483648;
	}
	for (j = 1; j <= n; j++){
		dyn[j] = 1;
		for (k = 0; k < j; k++){
			if (aray[k]<aray[j]){
				if (dyn[j] < dyn[k] + 1){
					dyn[j] = dyn[k] + 1;
					btk[j] = k;
				}
			}
		
		}
		j = j;
		if (dyn[j] > maxi){
			maxi = dyn[j];
			max_place = j;
		}
	}
	cout << maxi << endl;
	long long top = 0;
	bt2[++top] = max_place;
	while (btk[max_place] != 2147483648) {
		bt2[++top] = btk[max_place];
		max_place = btk[max_place];
	}
	for (i = top; i >= 1; i--) {
		cout << aray[bt2[i]] << " ";
	}
}