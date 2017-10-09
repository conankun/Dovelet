#include<iostream>
#include<string>
using namespace std;
string s;
string dna;
int dp[1000][1000];
int n;
int main() {
	int i,j,k,d;
	getline(cin,s);
	dna.resize(s.size()+1);
	n = s.size();
	for(i=0;i<s.size();i++) {
		dna[i+1] = s[i];
	}
	int mx=0;
	for(d=1;d<=n;d++) {
		for(i=1;i<=n-d+1;i++) {
			dp[i][i]=0;
			j = i+d-1;
			if(dna[i] == 'a' && dna[j] == 't') {
				dp[i][j] = max(dp[i][j],dp[i+1][j-1]+2);
			} else if(dna[i] == 'g' && dna[j] == 'c') {
				dp[i][j] = max(dp[i][j],dp[i+1][j-1]+2);
			}
			dp[i][j] = max(dp[i][j],max(dp[i][j-1],dp[i+1][j]));
			for(k=i+1;k<j;k++) {
				if(dp[i][k] > 0 && dp[k+1][j] > 0)
				dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
			if(mx < dp[i][j]) mx = dp[i][j];
		}
	}
	cout<<mx;
}