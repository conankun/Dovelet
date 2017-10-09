#include<iostream>
#include<string>
using namespace std;
char A[10] = { 'A', 'B', 'C' };
char B[10] = { 'B', 'A', 'B', 'C' };
char C[10] = { 'C', 'C', 'A', 'A', 'B', 'B' };
int main() {
	int N;
	cin >> N;
	string str;
	cin >> str;
	int i;
	int sz = str.size();
	int a = 0, b = 0, c = 0;
	for (i = 0; i < sz; i++) {
		if (A[i % 3] == str[i]) a++;
		if (B[i % 4] == str[i]) b++;
		if (C[i % 6] == str[i]) c++;
	}
	int mx = 0;
	if (a > mx) mx = a;
	if (b > mx) mx = b;
	if (c > mx) mx = c;
	cout << mx << endl;
	if (mx == a) cout << "Adrian" << endl;
	if (mx == b) cout << "Bruno" << endl;
	if (mx == c) cout << "Goran" << endl;
}