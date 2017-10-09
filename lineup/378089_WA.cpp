#include<iostream>
using namespace std;
int n,k;
int cows[100001];
int isLast[100001];
int vis[100001];
int chk[100001];
int size=1;
struct A {
	int ind,value;
};
A tree[1000000];
int main() {
	scanf("%d%d",&n,&k);
	int i;
	int mn=99999999;
	int mx=0;
	for(i=1;i<=n;i++) {
		scanf("%d",&cows[i]);
		if(cows[i] > mx) mx = cows[i];
	}
	for(;size<mx;size*=2);
	for(i=0;i<1000000;i++) tree[i].value = 999999999;
	for(i=n;i>=1;i--) {
		if(vis[cows[i]]==0) {
			isLast[i]=true;
		}
		vis[cows[i]]=1;
	}
	for(i=1;i<=n;i++) {
		if(isLast[i]) {
			int ls = size,rs = size+cows[i]-1;
			bool ok=true;
			int mi=999999999;
			while(ls<=rs&&ok) {
				if(ls==rs) ok=false;
				if(ls%2 == 1) {
					if(tree[ls].value < mi) mi = tree[ls].value;
					ls++;
				} 
				if(rs%2 == 1) {
					if(tree[rs].value < mi) mi = tree[rs].value;
					rs--;
				}
				ls/=2;
				rs/=2;
			}
			if(mn > mi+2) mn = mi+2;
		}
		A a;
		a.ind = cows[i];
		a.value = ++chk[cows[i]];
		int rs= size+a.ind-1;
		while(rs > 0) {
			if(tree[rs].ind == a.ind || tree[rs].value > a.value) {
				tree[rs] = a;
			}
			rs/=2;
		}
	}
	cout<<mn;
}