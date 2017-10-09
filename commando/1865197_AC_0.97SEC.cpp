#include<iostream>
typedef long long ll;
using namespace std;
int n;
ll A, B, C;
ll S[1111111];
ll D[1111111];
ll Test1(int n, int i) {
	return -2 * A*S[n] * S[i] + A*S[i] * S[i] - B*S[i] + D[i];
}
double Test2(int i, int j) {
	return (A*(S[j] * S[j] - S[i] * S[i]) - B*(S[j] - S[i]) + D[j] - D[i]) / (double)(2 * A*(S[j] - S[i]));
}
int queue[1111111];
int front = 1, back = 0;
int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin >> n >> A >> B >> C;
	int i, j;
	for (i = 1; i <= n; i++) {
		cin >> S[i];
		S[i] += S[i - 1];
	}
	queue[++back] = 0;
	for (i = 1; i <= n; i++) {
		int ind = 0;
		for (j = front; j<back; j++) {
			if (Test2(queue[j], queue[j + 1]) < S[i]) front++;
			else break;
		}
		ind = queue[front];
		D[i] = A*S[i] * S[i] + B*S[i] + C - 2 * A*S[i] * S[ind] + A*S[ind] * S[ind] - B*S[ind] + D[ind];
		for (j = back; j>front; j--) {
			if (Test2(i, queue[j-1]) < Test2(queue[j-1], queue[j])) back--;
			else break;
		}
		queue[++back] = i;
	}
	cout << D[n];
}