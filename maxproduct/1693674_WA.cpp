#include<algorithm>
#include<iostream>
using namespace std;
double maxi = -23.56;
double given[12340];
double dyn[12340];
double max(double a, double b){
	if (b - a > 0){
		return b;
	}
	return a;
}

int main(){
	dyn[0] = 1;
	int i, j,n;
	cin >> n;
	for (i = 1; i <= n; i++){
		cin >> given[i];
	}
	for (j = 1; j <= n; j++){
		dyn[j] = max(given[j], given[j] * dyn[j - 1]);
		if (dyn[j] > maxi){
			maxi = dyn[j];
		}
	}
	cout << maxi;
}