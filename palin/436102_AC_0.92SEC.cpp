#include<iostream>
using namespace std;
char s[10000];
char s2[10000];
int n;
FILE *in = stdin;
FILE *out = stdout;
int dp[5010][5010];
int main() {
	int i,j;
	fscanf(in,"%d",&n);
	fscanf(in,"%s",&s[1]);
	int ind=1;
	for(i=n;i>=1;i--) {
		s2[ind++] = s[i];
	}
	int mx=0;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			if(s[i] == s2[j]) {
				dp[i][j] = dp[i-1][j-1]+1;
				if(mx < dp[i][j]) mx = dp[i][j];
			} else {
				dp[i][j] = dp[i-1][j];
				if(dp[i][j] < dp[i][j-1]) dp[i][j] = dp[i][j-1];
			}
		}
	}
	fprintf(out,"%d",n-mx);
}