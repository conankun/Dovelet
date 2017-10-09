#include<iostream>
#include<cmath>
typedef long long ll;
using namespace std;
int main() {
	ll N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	int i;
	ll limit = sqrt(N);
	ll cost = -1;
	for (i = 1; i <= limit; i++) {
		//첫번째껄 i개 고름
		//i, (N-A*i) / C + ((N-A*i) % C == 0 ? 0 : 1)
		ll a = i;
		ll b = (N - A*i) / C;
		if (b < 0) b = 0;
		if (a*A + b*C < N) b++;
		if (cost == -1 || cost > a*B + b*D) {
			cost = a*B + b*D;
		}
	}
	for (i = 1; i <= limit; i++) {
		//두번째껄 i개 고름
		ll a = (N - C*i) / A;
		if (a < 0) a = 0;
		ll b = i;
		if (a*A + b*C < N) a++;
		if (cost == -1 || cost > a*B + b*D) {
			cost = a*B + b*D;
		}
	}
	cout << cost;
}