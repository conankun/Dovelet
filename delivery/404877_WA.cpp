#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int n,m;
char c[1000][1000];
struct B {
	int dis1,dis2;
};
B dp[1000][1000];
struct A {
	int y,x,dis;
};
A houses[1000];
A s1;
int ind=1;
bool cmp(A a,A b) {
	return abs(s1.x-a.x)+abs(s1.y-a.y) < abs(s1.x-a.x)+abs(s1.y-a.y);
}
int main() {
	cin>>n>>m;
	int i,j;
	bool t=false;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			cin>>c[i][j];
			if(c[i][j] == 'S') {
				s1.y = i;
				s1.x = j;
			} else if(c[i][j] == 'H') {
				houses[ind].y=i;
				houses[ind++].x=j;
			}
		}
	}
	houses[0].x=s1.x;
	houses[0].y=s1.y;
	for(i=0;i<=n;i++) for(j=0;j<=n;j++) {dp[i][j].dis1=99999999;dp[i][j].dis2=99999999;}
	sort(houses+1,houses+1+ind,cmp);
	dp[0][1].dis2=abs(s1.x-houses[1].x)+abs(s1.y-houses[1].y);
	dp[0][1].dis1=0;
	ind--;
	for(i=2;i<=ind;i++) {
		for(j=0;j<i;j++) {
			if(i!=2&&i-1==j) continue;
			if(max(dp[j][i-1].dis2,dp[j][i-1].dis1+(abs(s1.x-houses[j].x)+abs(s1.y-houses[j].y))+abs(s1.x-houses[i].x)+abs(s1.y-houses[i].y)) < max(dp[i-1][i].dis1,dp[i-1][i].dis2)) {
				dp[i-1][i].dis1=dp[j][i-1].dis2;
				dp[i-1][i].dis2=dp[j][i-1].dis1+(abs(s1.x-houses[j].x)+abs(s1.y-houses[j].y))+abs(s1.x-houses[i].x)+abs(s1.y-houses[i].y);
			}
			if(max(dp[j][i-1].dis1,dp[j][i-1].dis2+(abs(s1.x-houses[i-1].x)+abs(s1.y-houses[i-1].y))+abs(s1.x-houses[i].x)+abs(s1.y-houses[i].y)) < max(dp[j][i].dis1,dp[j][i].dis2)) {
				dp[j][i].dis1=dp[j][i-1].dis1;
				dp[j][i].dis2=dp[j][i-1].dis2+(abs(s1.x-houses[i-1].x)+abs(s1.y-houses[i-1].y))+abs(s1.x-houses[i].x)+abs(s1.y-houses[i].y);
			}
		}
	}
	int mn=99999999;
	for(i=0;i<ind;i++) {
		if(mn > max(dp[i][ind].dis1,dp[i][ind].dis2)) mn = max(dp[i][ind].dis1,dp[i][ind].dis2);
	}
	cout<<mn;
}