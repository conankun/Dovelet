#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
ll S[111111];
ll D[2][111111];
int bt[202][111111];
int N, K;

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
		int c1,d1;
		for (i = 1; i <= N; i++) {
			for (j = s; j <= e-1; j++) {
				a = qu[j], b = qu[j+1];
				c1 = S[a], d1 = S[b];
				if(S[a] == S[b])gg=0;
				else gg=(double)(D[!kg][b] - D[!kg][a] - d1*d1 + c1*c1) / (c1-d1);
				if (gg <= S[i]) s++;
				else break;
			}
			j = qu[s];
			
			for (j = e; j > s; j--) {
				a = qu[j], b = qu[j-1];
				c1 = S[a], d1 = S[b];
				if(S[a] == S[b])gg=0;
				else gg=(double)(D[!kg][b] - D[!kg][a] - d1*d1 + c1*c1) / (c1-d1);
				
				a = qu[j-1], b = i;
				c1 = S[a], d1 = S[b];
				if(a == b)gg2=0;
				else gg=(double)(D[!kg][b] - D[!kg][a] - d1*d1 + c1*c1) / (c1-d1);
				if (gg >= gg2) {
					e--;
				}
				else break;
			}
			D[kg][i] = D[!kg][j] + S[j] * (S[i] - S[j]);
			bt[k][i] = j;
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