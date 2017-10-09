#include<algorithm>
#include<iostream>
using namespace std;
int sum;
long long dyn[4000];

int main(){
	dyn[0] = 1;
	int i, j, n;
	cin >> n;
	sum = (n*(n + 1)) / 4;
	for (i = 1; i <= n; i++){
		for (j = sum; j >= 0; j--) {
			dyn[i + j] += dyn[j];
		}
	}
	if ((n*(n + 1)/2) % 2 == 1) cout << 0;
	else cout << dyn[sum]/2;
}
