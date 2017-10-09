#include<iostream>
using namespace std;
int n;
char code[100];
int value[100];
int mxchk[100];
struct A {
char cod;
int s,e;
};
A vert[100];
int main() {
	cin>>n;
	int d,i,j,k,l;
	for(i=1;i<=n;i++) {
		cin>>code[i]>>value[i];
	}
	for(i=1;i<=n;i++) {
		vert[i].cod = code[i];
		vert[i].s = value[i-1];
		vert[i].e = value[i];
		if(i == 1) vert[i].s = value[n];
	}
	int ans=0;
	for(l=1;l<=n;l++) {
		int dp[100][100]={0};
		int mndp[100][100]={0};
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) mndp[i][j]=99999999;
		int ve[100]={0};
		char cod[100]={0};
		int ind=1;
		int ind2=1;
		for(i=l+1;;i++) {
			if(i > n) {
				i=0;
			} else {
				if(i == l) break;
				ve[ind++]=vert[i].s;
				cod[ind2++]=vert[i].cod;
			}
		}
		ve[ind++]=vert[l].s;
		cod[ind2++]=vert[l].cod;
		for(d=1;d<=n;d++) {
			for(i=1;i<=n-d+1;i++) {
				j = i+d-1;
				dp[i][i] = ve[i];
				mndp[i][i] = ve[i];
				int v = -9999999;
				int m=99999999;
				for(k=i;k<j;k++) {
					if(cod[k] == 't') {
						if(v < dp[i][k]+dp[k+1][j]) v = dp[i][k]+dp[k+1][j];
						if(m > dp[i][k]+mndp[k+1][j]) m = dp[i][k]+mndp[k+1][j];
						if(m > mndp[i][k]+dp[k+1][j]) m = mndp[i][k]+dp[k+1][j];
						if(m > mndp[i][k]+mndp[k+1][j]) m = mndp[i][k]+mndp[k+1][j];
					} else {
						if(v < dp[i][k]*dp[k+1][j]) v = dp[i][k]*dp[k+1][j];
						if(v < dp[i][k]*mndp[k+1][j]) v = dp[i][k]*mndp[k+1][j];
						if(v < mndp[i][k]*dp[k+1][j]) v = mndp[i][k]*dp[k+1][j];
						if(v < mndp[i][k]*mndp[k+1][j]) v = mndp[i][k]*mndp[k+1][j];
						if(m > dp[i][k]*mndp[k+1][j]) m = dp[i][k]*mndp[k+1][j];
						if(m > mndp[i][k]*dp[k+1][j]) m = mndp[i][k]*dp[k+1][j];
						if(m > mndp[i][k]*mndp[k+1][j]) m = mndp[i][k]*mndp[k+1][j];
					}
				}
				if(j != i) dp[i][j] = v;
				if(j != i && m < 99999999) mndp[i][j] = m;
			}
		}
		if(dp[1][n] > ans) {
			ans = dp[1][n];
		}
		mxchk[l] = dp[1][n];
	}
	cout<<ans<<endl;
	for(i=1;i<=n;i++) if(mxchk[i] == ans) cout<<i<<" ";
}