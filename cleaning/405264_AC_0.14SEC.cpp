#include<iostream>
#include<algorithm>
using namespace std;
struct A {
	int s,e;
	bool operator<(const A &a) const {
		if(a.s == s) return e < a.e;
		return s < a.s;
	}
};
int n,t;
A pos[100000];
int dp[100000];
int tree[10000000];
int main() {
	scanf("%d%d",&n,&t);
	int i;
	for(i=1;i<=n;i++) scanf("%d%d",&pos[i].s,&pos[i].e);
	sort(pos+1,pos+1+n);
	int size=1;
	for(;size<1100000;size*=2);
	for(i=1;i<=n;i++) {
		int ls=size+pos[i].s-1,rs=size+pos[i].e;
		bool t=true;
		int mn=99999999;
		while(ls<=rs&&t) {
			if(ls==rs)t=false;
			if(ls%2 == 1) {
				if(tree[ls] > 0 && tree[ls] < mn) mn = tree[ls];
				ls++;
			}
			if(rs%2 == 0) {
				if(tree[rs] > 0 && tree[rs] < mn) mn = tree[rs];
				rs--;
			}
			ls/=2;
			rs/=2;
		}
		if(mn == 99999999) {
			if(pos[i].s == 1) {
				dp[i]=1;
				int rs = size+pos[i].e;
				while(rs > 0) {
					if(tree[rs] == 0 || tree[rs] > dp[i]) tree[rs] = dp[i];
					rs/=2;
				}
			} else {
				dp[i]=99999999;
			}
		} else {
			dp[i] = mn+1;
			int rs = size+pos[i].e;
			while(rs > 0) {
				if(tree[rs] == 0 || tree[rs] > dp[i]) tree[rs] = dp[i];
				rs/=2;
			}
		}
	}
	int mn=99999999;
	for(i=1;i<=n;i++) {
		if(pos[i].e >= t && dp[i] < mn) mn = dp[i];
	}
	if(mn == 99999999) mn = -1;
	printf("%d",mn);
}