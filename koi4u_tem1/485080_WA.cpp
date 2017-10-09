#include<stdio.h>
#include<map>
#include<algorithm>
int N;
struct A {
	int a,b;
}tem[1111111];
struct B {
	int value,ind,p;
	bool operator<(const B &b) const {
		return value < b.value;
	}
}sorted[1111111];
struct C {
	int ind,value,high;
}tree[3000000],qu[1111111];
int key[2][1111111];
std::map<int,int> mp;
int main() {
	scanf("%d",&N);
	int i,j;
	int cnt=0;
	for(i=1;i<=N;i++) {
		scanf("%d%d",&tem[i].a,&tem[i].b);
		sorted[++cnt].value = tem[i].a;
		sorted[cnt].ind = i;
		sorted[cnt].p = 0;
		sorted[++cnt].value = tem[i].b;
		sorted[cnt].ind = i;
		sorted[cnt].p = 1;
	}
	sorted[0].value = -2147483647;
	std::stable_sort(sorted+1,sorted+1+cnt);
	int lank=0;
	for(i=1;i<=cnt;i++) {
		if(sorted[i].value != sorted[i-1].value) lank++;
		key[sorted[i].p][sorted[i].ind]=lank;
		mp[sorted[i].value]=lank;
	}
	int size=1;
	for(;size<cnt;size*=2);
	int ans=1;
	int h,t;
	for(i=1;i<=N;i++) {
		int ls=size+1,rs=size+key[1][i];
		bool ok=true;
		h=1,t=0;
		while(ls<=rs&&ok) {
			if(ls==rs) ok=false;
			if(ls%2==1) {
				if(tree[ls].ind==i-1 && tree[ls].high <= tem[i].b && i>1) {
					qu[++t] = tree[ls];
					if(ans < tree[ls].value+1) ans = tree[ls].value+1;
					qu[t].ind = i;
					qu[t].value=qu[t].value+1;
					qu[t].high = (qu[t].high < tem[i].a?tem[i].a:qu[t].high);
				}
				ls++;
			}
			if(rs%2==0) {
				if(tree[rs].ind == i-1 && tree[rs].high <= tem[i].b && i>1) {	
					qu[++t] = tree[rs];
					if(ans < tree[rs].value+1) ans = tree[rs].value+1;
					qu[t].ind = i;
					qu[t].value=qu[t].value+1;
					qu[t].high = (qu[t].high < tem[i].a?tem[i].a:qu[t].high);
				}
			}
			ls/=2;
			rs/=2;
		}
		qu[++t].high=tem[i].a;
		qu[t].value = 1;
		qu[t].ind = i;
		while(h<=t) {
			std::map<int,int>::iterator it = mp.find(qu[h].high);
			if(it != mp.end()) {
				rs = it->second+size;
				while(rs>0) {
					if(tree[rs].ind != i || tree[rs].value < qu[h].value) {
						tree[rs] = qu[h];
					}
					rs/=2;
				}
			}
			h++;
		}
	}
	printf("%d",ans);
}