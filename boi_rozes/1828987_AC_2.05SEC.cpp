#include<iostream>
#include<cmath>
typedef long long ll;
using namespace std;
int min(int a, int b) {
	if (a < b) return a;
	return b;
}
int main() {
	ll N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	int i;
	int limit = sqrt(N);
	ll cost = -1;
	ll a, b;
	for (i = 0; i <= min(500000,limit); i++) {
		//첫번째껄 i개 고름
		//i, (N-A*i) / C + ((N-A*i) % C == 0 ? 0 : 1)
		a = i;
		b = (N - A*i) / C;
		if (b < 0) b = 0;
		if (a*A + b*C < N) b++;
		if (cost == -1 || cost > a*B + b*D) {
			cost = a*B + b*D;
		}
		//두번째껄 i개 고름
		a = (N - C*i) / A;
		if (a < 0) a = 0;
		b = i;
		if (a*A + b*C < N) a++;
		if (cost == -1 || cost > a*B + b*D) {
			cost = a*B + b*D;
		}
	}
	cout << cost;
}