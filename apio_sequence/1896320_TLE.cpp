#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
ll S[111111];
ll D[2][111111];
int bt[202][111111];
int N, K;
inline double g(int k, int a, int b) {
	if (S[a] == S[b]) return 0;
	return (double)(D[1-k][b] - D[1-k][a] - S[b] * S[b] + S[a] * S[a]) / (S[a]-S[b]);
}
inline ll max(ll a, ll b) {
	if (a > b) return a;
	return b;
}
int qu[111111];
int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin >> N >> K;
	int i,j, k;
	for (i = 1; i <= N; i++) {
		cin >> S[i];
		S[i] += S[i - 1];
	}
	for (k = 1; k <= K; k++) {
		int s = 1, e = 0, kg = k % 2;
		for (i = 1; i <= N; i++) {
			for (j = s; j <= e-1; j++) {
				if (g(kg, qu[j], qu[j + 1]) <= S[i]) s++;
				else break;
			}
			j = qu[s];
			D[kg][i] = D[1-kg][j] + S[j] * (S[i] - S[j]);
			bt[k][i] = j;
			for (j = e; j > s; j--) {
				if (g(kg, qu[j], qu[j - 1]) >= g(kg, qu[j - 1], i)) {
					e--;
				}
				else break;
			}
			qu[++e] = i;
		}
	}
	ll ans = D[K%2][N];
	cout << ans << endl;
	k = K; i = N;
	vector<int> btans;
	while (bt[k][i] != 0) {
		btans.push_back(bt[k][i]);
		i = bt[k][i];
		k--;
	}
	sort(btans.begin(), btans.end());
	k = btans.size();
	for (i = 0; i < k; i++) {
		cout << btans[i] << " ";
	}
}