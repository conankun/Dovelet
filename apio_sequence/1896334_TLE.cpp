#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
ll S[111111];
ll D1[111111];
ll D0[111111];
int bt[202][111111];
int N, K;
inline double g(int k, int a, int b) {
	if (S[a] == S[b]) return 0;
	if(k == 0) return (double)(D1[b] - D1[a] - S[b] * S[b] + S[a] * S[a]) / (S[a]-S[b]);
	return (double)(D0[b] - D0[a] - S[b] * S[b] + S[a] * S[a]) / (S[a]-S[b]);
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
		int s = 1, e = 0, kg = k % 2, a=0,b=0;
		double gg=0,gg2=0;
		for (i = 1; i <= N; i++) {
			for (j = s; j <= e-1; j++) {
				a = qu[j], b = qu[j+1];
				if(S[a] == S[b])gg=0;
				else if(kg == 1) gg=(double)(D0[b] - D0[a] - S[b] * S[b] + S[a] * S[a]) / (S[a]-S[b]);
				else if(kg == 0) gg=(double)(D1[b] - D1[a] - S[b] * S[b] + S[a] * S[a]) / (S[a]-S[b]);
				if (gg <= S[i]) s++;
				else break;
			}
			j = qu[s];
			//D[kg][i] = D[1-kg][j] + S[j] * (S[i] - S[j]);
			if(kg == 0) D0[i] = D1[j]+S[j] * (S[i]-S[j]);
			else D1[i] = D0[j]+S[j]*(S[i]-S[j]);
			bt[k][i] = j;
			for (j = e; j > s; j--) {
				a = qu[j], b = qu[j-1];
				if(S[a] == S[b])gg=0;
				else if(kg == 1) gg=(double)(D0[b] - D0[a] - S[b] * S[b] + S[a] * S[a]) / (S[a]-S[b]);
				else if(kg == 0) gg=(double)(D1[b] - D1[a] - S[b] * S[b] + S[a] * S[a]) / (S[a]-S[b]);
				
				a = qu[j-1], b = i;
				if(a == b)gg2=0;
				else if(kg == 1) gg2=(double)(D0[b] - D0[a] - S[b] * S[b] + S[a] * S[a]) / (S[a]-S[b]);
				else if(kg == 0) gg2=(double)(D1[b] - D1[a] - S[b] * S[b] + S[a] * S[a]) / (S[a]-S[b]);
				if (gg >= gg2) {
					e--;
				}
				else break;
			}
			qu[++e] = i;
		}
	}
	ll ans = D1[N];
	if(K % 2 == 0) ans = D0[N];
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