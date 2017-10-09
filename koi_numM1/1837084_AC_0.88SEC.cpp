#include<iostream>
typedef long long ll;
using namespace std;
ll gcd(ll a, ll b) {
	ll c;
	do {
		c = a%b;
		a = b;
		b = c;
	} while (c != 0);
	return a;
}
int main() {
	ll a, b;
	cin >> a >> b;
	ll i;
	ll mn = -1;
	ll c = 0, d = 0;
	for (i = a; i <= b; i+=a) {
		if (i == 11648) {
			i = i;
		}
		if ((a*b) % i != 0) continue;
		ll temp = a*b / i;
		if (gcd(i, temp) != a) continue;
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