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
int dyn[500];
int maxi = -89;
int main(){
	dyn[0] = 0;
	int i, j, n;
	cin >> n;
	for (i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for (i = 1; i <= n; i++){
		for (j = 0; j < i; j++){
			if (arr[j] < arr[i]) {
				dyn[i] = max(dyn[i], dyn[j] + 1);
			}
		}
		if (dyn[i] > maxi){
			maxi = dyn[i];
		}
	}
	cout << maxi;
}