#include<iostream>
using namespace std;
int b1,b2,b3;
int dp[1000][1000];
int min(int a,int b) {
	if(a < b) return a;
	return b;
}
int main() {
	cin>>b1>>b2>>b3;
	int i,j;
	dp[0][0]=-1;
	for(i=0;i<=500;i++) {
		for(j=0;j<=500;j++) {
			if(i == j && i == 0) continue;
			int a = (i-b1 >= 0 ? dp[i-b1][j] : 9999999);
			int b = (i-b2 >= 0 ? dp[i-b2][j] : 9999999);
			int c = (i-b3 >= 0 ? dp[i-b3][j] : 9999999);
			int d = (j-b1 >= 0 ? dp[i][j-b1] : 9999999);
			int e = (j-b2 >= 0 ? dp[i][j-b2] : 9999999);
			int f = (j-b3 >= 0 ? dp[i][j-b3] : 9999999);
			if(a == -1 || b == -1 || c == -1 || d == -1 || e == -1 || f == -1) {
				dp[i][j] = 1;
			} else dp[i][j] = -1;
		}
	}
	for(i=1;i<=5;i++) {
		int a,b;
		cin>>a>>b;
		if(dp[a][b] == -1) cout<<"B"<<endl;
		else cout<<"A"<<endl;
	}
}