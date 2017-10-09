#include<stdio.h>
#include<algorithm>
using namespace std;
int N,K;
int seq[1111111];
int key[1111111];
int tree[5000000];
struct A {
	int ind,value;
	bool operator<(const A &a) const {
		return value < a.value;
	}
}sorted[1111111];
int main() {
	scanf("%d%d",&N,&K);
	int i;
	for(i=1;i<=N;i++) {
		scanf("%d",&seq[i]);
		sorted[i].value = seq[i];
		sorted[i].ind = i;
	}
	int keys=0;
	stable_sort(sorted+1,sorted+1+N);
	for(i=1;i<=N;i++) {
		if(sorted[i].value != sorted[i-1].value) keys++;
		key[sorted[i].ind]=keys;
	}
	int size=1;
	for(;size<N;size*=2);
	int ans=0;
	for(i=1;i<=N;i++) {
		int ls=size+1,rs=size+key[i]-1;
		bool ok=true;
		int mx=0;
		while(ls<=rs&&ok) {
			if(ls%2==1) {
				if(tree[ls]>mx) mx = tree[ls];
				ls++;
			}
			if(rs%2==0) {
				if(tree[rs]>mx) mx = tree[rs];
				rs--;
			}
			ls/=2;
			rs/=2;
		}
		if(mx+1 > ans) ans = mx+1;
		rs=size+key[i];
		while(rs>0) {
			if(tree[rs]<mx+1) tree[rs]=mx+1;
			rs/=2;
		}
	}
	if(ans>K) ans=K;
	printf("%.2lf%%",(ans/(double)K)*100);
}