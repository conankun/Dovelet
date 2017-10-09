#include<iostream>
using namespace std;
int n;
int init[10002];
int want[10002];
int rights[10][10];
int lefts[10][10];
int rightnum[10][10];
int leftnum[10][10];
int dp[10002][11];
int backpoints[10002][11];
int back[10002][11];
int min(int a,int b) {
	if(a < b) return a;
	return b;
}
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) {
		char c;
		cin>>c;
		init[i] = c-48;
	}
	for(i=1;i<=n;i++) {
		char c;
		cin>>c;
		want[i] = c-48;
	}
	for(i=0;i<=9;i++) {
		int cnt=1;
		for(j=i+1;;j++) { //왼쪽으로 돌리는거.
			if(j == i) break;
			if(j > 9) {
				j = -1;
				continue;
			}
			lefts[i][j] = cnt;
			leftnum[i][cnt]=j;
			cnt++;
			if(j == 9) j=-1;
		}
		lefts[i][i] = 0;
		leftnum[i][0] = i;
		cnt=1;
		for(j=i-1;;j--) { //오른쪽으로 돌리는거.
			if(j == i) break;
			if(j < 0) {
				j=10;
				continue;
			}
			rights[i][j] = cnt;
			rightnum[i][cnt]=j;
			cnt++;
			if(j == 0) j=10;
		}
		rights[i][i] = 0;
		rightnum[i][0] = i;
	}
	for(i=n;i>=1;i--) {
		for(j=0;j<=9;j++) {
			int s = init[i];
			int e = want[i];
			int ee = want[i+1];
			int a = rightnum[e][j];
			int alen = rights[e][a]; //e<->a 의 거리.
			int b = lefts[s][a]; //s<->a의 거리.
			if(i == n) {
				dp[i][j] = min(lefts[s][a],rights[s][a]);
				if(lefts[s][a] < rights[s][a]) {
					back[i][j] = lefts[s][a];
				} else {
					back[i][j] = rights[s][a]*-1;
				}
			} else {
				dp[i][j] = min(b+dp[i+1][(alen+b)%10],rights[s][a]+dp[i+1][j]);
				if(b+dp[i+1][(alen+b)%10] < rights[s][a]+dp[i+1][j]) {
					back[i][j] = b;
					backpoints[i][j] = (alen+b)%10;
				} else {
					back[i][j] = rights[s][a]*-1;
					backpoints[i][j] = j;
				}
			}
		}
	}
	cout<<dp[1][0]<<endl;
	int a = 0;
	int sum=0;
	for(i=1;i<=n;i++) {
		if(back[i][a] > 0 && back[i][a] > 0) {
			cout<<i<<" "<<back[i][a]<<endl;
			if(back[i][a] > 0) sum+=back[i][a];
			sum%=10;
		} else if(back[i][a] < 0) {
			cout<<i<<" "<<back[i][a]<<endl;
		}
		a = backpoints[i][a];
	}
}