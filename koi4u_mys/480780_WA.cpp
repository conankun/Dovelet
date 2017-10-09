#include<stdio.h>
#include<algorithm>
using namespace std;
int N,W,H;
struct A {
	int w,h,index;
	bool operator<(const A &a) const {
		if(a.w == w) return h < a.h;
		return w < a.w;
	}
}pre[333333];
struct B {
	int value,ind;
}tree[10000000];
struct C {
	int value,ind,limit;
}qu[333333];
int back[333333];
int h=1,t;
int main() {
	scanf("%d%d%d",&N,&W,&H);
	int i;
	for(i=1;i<=N;i++) {
		scanf("%d%d",&pre[i].w,&pre[i].h);
		pre[i].index=i;
	}
	stable_sort(pre+1,pre+1+N);
	int size=1;
	for(;size<3000001;size*=2);
	int mx=0,mxindex=0;
	for(i=1;i<=N;i++) {
		if(pre[i].w <= W || pre[i].h <= H) continue;
		int ls=size+1,rs=size+pre[i].h-1;
		bool ok=true;
		int ans=0,index=0;
		while(ls<=rs&&ok) {
			if(ls==rs) ok=false;
			if(ls%2==1) {
				if(ans < tree[ls].value) {
					ans = tree[ls].value;
					index = tree[ls].ind;
				}
				ls++;
			}
			if(rs%2==0) {
				if(ans < tree[rs].value) {
					ans = tree[rs].value;
					index = tree[rs].ind;
				}
				rs--;
			}
			ls/=2;
			rs/=2;
		}
		back[i] = index;
		qu[++t].ind = i;
		qu[t].limit = size+pre[i].h;
		qu[t].value = ans+1;
		if(ans+1 > mx) {
			mx=ans+1;
			mxindex = i;
		}
		if(pre[i].w != pre[i+1].w) {
			while(h<=t) {
				B bb;
				bb.ind = qu[h].ind;
				bb.value = qu[h].value;
				rs = qu[h].limit;
				while(rs>0) {
					if(tree[rs].value < bb.value) {
						tree[rs] = bb;
					}
					rs/=2;
				}
				h++;
			}
			h=1,t=0;
		}
	}
	h=1,t=0;
	printf("%d\n",mx);
	int bt = mxindex;
	qu[++t].value=bt;
	while(bt>0) {
		bt = back[bt];
		if(bt != 0) qu[++t].value = bt;
	}
	if(mx!=0)
	for(i=t;i>=1;i--) printf("%d ",pre[qu[i].value].index);
}