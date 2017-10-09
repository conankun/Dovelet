#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,int> mp;
int vertex[1000][1000];
int dp[1000][1000];
int N,V;
int main() {
	cin>>N>>V;
	int i,j,k;
	for(i=1;i<=N;i++) {
		string s;
		cin>>s;
		mp[s]=i;
	}
	for(i=1;i<=V;i++) {
		string a,b;
		cin>>a>>b;
		vertex[mp[a]][mp[b]]=1;
		vertex[mp[b]][mp[a]]=1;
	}
	dp[1][1]=1;
	for(i=1;i<=N;i++) {
		for(k=1;k<=i-1;k++) {
			for(j=1;j<=k;j++) {
				if(dp[j][k]+1 > dp[j][i] && vertex[k][i] == 1 && dp[j][k] >= 1) {
					dp[j][i] = dp[j][k]+1;
				}
				if(dp[j][k]+1 > dp[k][i] && vertex[j][i] == 1 && dp[j][k] >= 1) {
					dp[k][i] = dp[j][k]+1;
				}
			}
		}
	}
	int mx=1;
	for(i=1;i<=N;i++) {
		if(vertex[i][N] == 1) {
			if(mx < dp[i][N]) mx = dp[i][N];
		}
	}
	cout<<mx;
}