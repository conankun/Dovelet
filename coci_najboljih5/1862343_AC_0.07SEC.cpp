#include<iostream>
#include<algorithm>
using namespace std;
struct A {
	int val;
	int ind;
	bool operator<(const A& a) const {
		return val > a.val;
	}
}arr[11];
int arr2[11];
int main() {
	int i;
	for (i = 1; i <= 8; i++) {
		cin >> arr[i].val;
		arr[i].ind = i;
	}
	sort(arr+ 1, arr + 9);
	int sum = 0;
	for (i = 1; i <= 5; i++) {
		arr2[i] = arr[i].ind;
		sum += arr[i].val;
	}
	sort(arr2 + 1, arr2 + 6);
	cout << sum << endl;
	for (i = 1; i <= 5; i++) cout << arr2[i] << " ";
}