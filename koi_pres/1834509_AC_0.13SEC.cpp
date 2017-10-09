#include<iostream>
#include<algorithm>
using namespace std;
int N;
struct A {
	int pt;
	int a[10];
	int num;
}arr[10];
bool cmp(A a, A b) {
	if (a.pt == b.pt) {
		if (a.a[3] == b.a[3]) {
			if (a.a[2] == b.a[2]) {
				return a.a[1] > b.a[1];
			}
			return a.a[2] > b.a[2];
		}
		return a.a[3] > b.a[3];
	}
	return a.pt > b.pt;
}
bool tie(A a, A b) {
	if (a.pt == b.pt && a.a[1] == b.a[1] && a.a[2] == b.a[2] && a.a[3] == b.a[3]) {
		return true;
	}
	return false;
}
int main() {
	cin >> N;
	int i;
	for (i = 1; i <= N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[1].pt += a;
		arr[2].pt += b;
		arr[3].pt += c;
		arr[1].a[a]++;
		arr[2].a[b]++;
		arr[3].a[c]++;
	}
	arr[1].num = 1;
	arr[2].num = 2;
	arr[3].num = 3;
	sort(arr + 1, arr + 4, cmp);
	if (tie(arr[1], arr[2]) || tie(arr[1], arr[3]) || tie(arr[2], arr[3])) {
		cout << "0 " << arr[1].pt;
		return 0;
	}
	cout << arr[1].num << " " << arr[1].pt;
}