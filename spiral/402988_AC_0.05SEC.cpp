#include<iostream>
using namespace std;
int map[100][100];
int n;
int main() {
	cin>>n;
	int i,j;
	int cnt=0;
	int t=0;
	while(cnt < n*n) {
		t++;
		for(i=1;i<=n;i++) {
			if(map[t][i] == 0) {
				cnt++;
				map[t][i]=cnt;
			}
		}
		for(i=1;i<=n;i++) {
			if(map[i][n-t+1] == 0) {
				cnt++;
				map[i][n-t+1]=cnt;
			}
		}
		for(i=n;i>=1;i--) {
			if(map[n-t+1][i] == 0) {
				cnt++;
				map[n-t+1][i]=cnt;
			}
		}
		for(i=n;i>=1;i--) {
			if(map[i][t] == 0) {
				cnt++;
				map[i][t]=cnt;
			}
		}
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			printf("%5d",map[i][j]);
		}
		printf("\n");
	}
}