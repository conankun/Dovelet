#include <iostream>
using namespace std;
int n;
int mat[20][20];
int D[100000][20];
int min(int a, int b) {
	if (a < b) return a;
	return b;
}
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			cin>>mat[i][j];
		}
	}
	for(i=0;i<(1<<n);i++) {
		for(j=1;j<=n;j++) {
			D[i][j] = 999999999;
		}
	}
	int s;
	int ans = -1;
	D[1][1] = 0;
	for(s=2;s<=n;s++) {
		for(i=0;i<(1<<n);i++) {
			int bits = 0;
			int k = i;
			if((k&1) == 0) continue; // if does not contain 1
			while(k > 0) {
				if((k & 1) == 0) {
					
				} else {
					bits++;
				}
				k/=2;
			}
			if(bits != s) continue; // if the size of the set is not s
			for(j=1;j<=n;j++) {
				if((i & (1<<(j-1))) == 0) continue; // if not in the set
				for(int l=1;l<=n;l++) {
					if(j == l) continue;
					if((i & (1 << (l-1))) == 0) continue;
					if(mat[l][j] == 0) continue;
					D[i][j] = min(D[i & ((1 << n) -1 - (1<<(j-1)))][l] + mat[l][j], D[i][j]);
					
					if(i == (1<<n) -1) {
						if(ans == -1 || ans > D[i][j] + mat[j][1]) {
							ans = D[i][j] + mat[j][1];
						}
					}
				}
			}
		}		
	}
	cout<<ans;
}