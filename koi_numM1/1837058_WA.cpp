#include<iostream>
typedef long long ll;
using namespace std;
int main() {
	ll a, b;
	cin >> a >> b;
	ll i;
	ll mn = -1;
	ll c = 0, d = 0;
	for (i = a; i <= b; i+=a) {
		if ((a*b) % i != 0) continue;
		ll temp = a*b / i;
		if (temp + i < mn || mn == -1) {
			mn = temp + i;
			if (temp > i) {
				d = temp;
				c = i;
			}
			else {
				c = temp;
				d = i;
			}
		}
	}
	cout << c << " " << d << endl;
}