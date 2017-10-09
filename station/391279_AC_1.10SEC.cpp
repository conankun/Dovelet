#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct A {
	int x,y;
	bool operator<(const A &a) const {
		if(a.x == x) return y < a.y;
		return x < a.x;
	}
};
A pos[10001];
int dp[10001];
int n;
int max(int a,int b) {
	if(a > b) return a;
	return b;
}
int main() {
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) cin>>pos[i].x>>pos[i].y;
	sort(pos+1,pos+1+n);
	for(i=1;i<=n;i++) {
		int mn=2147483647;
		int mxy = abs(pos[i].y);
		for(j=i-1;j>=0;j--) {
			if(abs(pos[j+1].y) > mxy) mxy = abs(pos[j+1].y);
			if(mn > dp[j]+max(abs(pos[j+1].x-pos[i].x),abs(mxy)*2)) {
				mn = dp[j]+max(abs(pos[j+1].x-pos[i].x),abs(mxy)*2);
			}
		}
		dp[i] = mn;
	}
	cout<<dp[n];
}