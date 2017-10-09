#include<iostream>
#include<algorithm>
using namespace std;
int a[10000];
int b[10000];
int n,m;
struct A {
	int a,b,c,d;
	bool operator<(const A &dd) const {
		return min(a,c) < min(dd.a,dd.c);
	}
};
int dp[10000];
A input[100000];
int ind=1;
int main() {
	cin>>n>>m;
	int i,j,k,l;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>b[i];
	for(i=1;i<=n;i++) {
		for(j=i+1;j<=n;j++) {
			for(k=1;k<=m;k++) {
				for(l=k+1;l<=m;l++) {
					if(a[i] == b[l] && /*a[j] == b[k] && */a[i] != a[j] && l >= i && k <= j) {
						A a;
						a.a = i;
						a.b = j;
						a.c = k;
						a.d = l;
						input[ind++]=a;
					}
				}
			}
		}
	}
	sort(input+1,input+ind);
	int maxs=0;
	for(i=1;i<ind;i++) {
		int mx=0;
		for(j=1;j<i;j++) {
			if(input[j].a < input[i].a && input[j].b < input[i].a && input[j].c < input[i].c && input[j].d < input[i].c) {
				if(dp[j] > mx) {
					mx = dp[j];
				}
			}
		}
		dp[i]=mx+1;
		if(dp[i] > maxs) {
			maxs = dp[i];
		}
	}
	cout<<maxs*2;
}