#include<iostream>
#include<string>
using namespace std;
int days[20] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string str[20] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
int main() {
	int a, b;
	cin >> b >> a;
	int i;
	int c = 1, d = 1;
	if (a == c && d == b) {
		cout << "Thursday";
			return 0;
	}
	int dd = 3;
	for (i = 1; i <= 365; i++) {
		d++;
		if (d > days[c - 1]) {
			c++;
			d = 1;
		}
		dd++;
		dd %= 7;
		if (a == c && b == d) {
			cout << str[dd];
			return 0;
		}
	}
}