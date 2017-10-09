#include<iostream>
using namespace std;
int n, m;
int arr1[1111];
int arr2[1111];
int dp[1111][1111];
int back[1111][1111];
int a, b,mx;
int bt[1111];
int ind;
int main() {
	cin >> n>>m;
	int i,j;
	for (i = 1; i <= n; i++) cin >> arr1[i];
	//cin >> m;
	for (i = 1; i <= m; i++) cin >> arr2[i];
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (dp[i - 1][j] > dp[i][j - 1]) {
				dp[i][j] = dp[i - 1][j];
				back[i][j] = 1; // i-1, no-show
			}
			else {
				dp[i][j] = dp[i][j - 1];
				back[i][j] = 2; // j-1, no-show
			}

			if (arr1[i] == arr2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				back[i][j] =3; // show
			}
			if (mx < dp[i][j]) {
				mx = dp[i][j];
				a = i;
				b = j;
			}
		}
	}
	while (back[a][b] > 0) {
		if (back[a][b] > 2) {
			bt[++ind] = arr1[a];
		}
		if (back[a][b] == 1) a--;
		else if(back[a][b] == 2) b--;
		else {
			a--; b--;
		}
	}
	cout << mx << endl;
	for (i = ind; i >= 1; i--) cout << bt[i] << " ";
}