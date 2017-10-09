#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
double dp[1001][1001];
int n;
struct A {
	int y,x;
	bool operator<(const A &a) const {
		return x < a.x;
	}
};
A pos[1001];
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) cin>>pos[i].x>>pos[i].y;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) dp[i][j]=999999999.00;
	sort(pos+1,pos+1+n);
	dp[1][1]=0;
	dp[1][2]=sqrt(pow(abs(pos[1].x-pos[2].x),2.00)+pow(abs(pos[1].y-pos[2].y),2.00));
	for(i=1;i<=n;i++) {
		double mn=99999999.00;
		dp[i][i]=0;
		for(j=1;j<i-1;j++) {
			if(dp[j][i-1]+sqrt(pow(abs(pos[i].x-pos[j].x),2.00)+pow(abs(pos[i].y-pos[j].y),2.00)) < dp[i-1][i]) {
				dp[i-1][i] = dp[j][i-1]+sqrt(pow(abs(pos[i].x-pos[j].x),2.00)+pow(abs(pos[i].y-pos[j].y),2.00));
			}
			if(dp[j][i-1]+sqrt(pow(abs(pos[i].x-pos[i-1].x),2.00)+pow(abs(pos[i].y-pos[i-1].y),2.00)) < dp[j][i]) {
				dp[j][i]=dp[j][i-1]+sqrt(pow(abs(pos[i].x-pos[i-1].x),2.00)+pow(abs(pos[i].y-pos[i-1].y),2.00));
			}
		}
	}
	double mn=999999999.00;
	for(i=1;i<=n-1;i++) {
		if(dp[i][n]+sqrt(pow(abs(pos[i].x-pos[n].x),2.00)+pow(abs(pos[i].y-pos[n].y),2.00)) < mn) {
			mn = dp[i][n]+sqrt(pow(abs(pos[i].x-pos[n].x),2.00)+pow(abs(pos[i].y-pos[n].y),2.00));
		}
	}
	printf("%.2lf",mn);
}