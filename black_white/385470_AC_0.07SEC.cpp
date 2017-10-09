#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int n;
int points[1000];
int dp[1000][1000];
int high[1000][1000];
struct A {
	int a,b;
	bool operator<(const A &c) const {
		return a < c.a;
	}
};
vector<A> ve[200][200];
int max(int a,int b) {
	if(a > b) return a;
	return b;
}
int main() {
	cin>>n;
	int d,i,j,k,z;
	for(i=1;i<=n;i++) {
		char c;
		cin>>c;
		points[i] = c-48;
	}
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) dp[i][j]=99999999;
	for(i=1;i<=n;i++) {
		if(points[i] == 1 && points[i+1] == 0) {
			dp[i][i+1]=3;
			high[i][i+1]=1;
			A a;
			a.a = i;
			a.b = i+1;
			ve[i][i+1].push_back(a);
		} else if(points[i] == 0 && points[i+1] == 1) {
			dp[i][i+1]=3;
			high[i][i+1]=1;
			A a;
			a.a = i;
			a.b = i+1;
			ve[i][i+1].push_back(a);
		}
	}
	for(d=3;d<=n;d++) {
		for(i=1;i<=n-d+1;i++) {
			j = d+i-1;
			int mn=99999999;
			int h=99999999;
			if(mn > dp[i+1][j-1]+(high[i+1][j-1]+1)*2+abs(j-i) && ((points[i] == 1 && points[j] == 0) || (points[i] == 0 && points[j] == 1))) {
				mn = dp[i+1][j-1]+(high[i+1][j-1]+1)*2+abs(j-i);
				h = high[i+1][j-1]+1;
				A a;
				a.a = i;
				a.b = j;
				ve[i][j].push_back(a);
				for(z=0;z<ve[i+1][j-1].size();z++) ve[i][j].push_back(ve[i+1][j-1][z]);
			}
			for(k=i+1;k<=j-1;k++) {
				if(mn > dp[i][k]+dp[k+1][j]) {
					mn = dp[i][k]+dp[k+1][j];
					h = max(high[i][k],high[k+1][j]);
					ve[i][j].clear();
					for(z=0;z<ve[i][k].size();z++) ve[i][j].push_back(ve[i][k][z]);
					for(z=0;z<ve[k+1][j].size();z++) ve[i][j].push_back(ve[k+1][j][z]);
				}
			}
			dp[i][j] = mn;
			high[i][j] = h;
		}
	}
	cout<<dp[1][n]<<endl;
	sort(ve[1][n].begin(),ve[1][n].end());
	for(i=0;i<ve[1][n].size();i++) cout<<ve[1][n][i].a<<" "<<ve[1][n][i].b<<endl;
}