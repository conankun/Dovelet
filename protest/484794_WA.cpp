#include<stdio.h>
#include<algorithm>
#define MOD 1000000009
int cow[100001];
int N;
int tree[300000];
int D[100001];
struct A {
	int ind,value;
	bool operator<(const A &a) const {
		return value < a.value;
	}
}keysort[111111];
int key[111111];
int main() {
	scanf("%d",&N);
	int i;
	keysort[1].value = 0;
	keysort[1].ind = 1;
	for(i=2;i<=N+1;i++) {
		scanf("%d",&cow[i]);
		cow[i]+=cow[i-1];
		keysort[i].value = cow[i];
		keysort[i].ind = i;
	}
	std::stable_sort(keysort+1,keysort+1+N+1);
	int lank=0;
	keysort[0].value = -12313123;
	for(i=1;i<=N+1;i++) {
		if(keysort[i].value != keysort[i-1].value) lank++;
		key[keysort[i].ind]=lank;
	}
	int size=1;
	for(;size<N;size*=2);
	D[1]=1;
	for(i=1;i<=N+1;i++) {
		int ls=size+1,rs=size+key[i];
		bool ok=true;
		int sum=0;
		while(ls<=rs&&ok) {
			if(ls==rs) ok=false;
			if(ls%2==1) {
				sum+=tree[ls];
				sum%=MOD;
				ls++;
			}
			if(rs%2==0) {
				sum+=tree[rs];
				sum%=MOD;
				rs--;
			}
			ls/=2;
			rs/=2;
		}
		D[i]+=sum;
		rs=size+key[i];
		while(rs>0) {
			tree[rs]+=D[i];
			tree[rs]%=MOD;
			rs/=2;
		}
	}
	printf("%d",D[N+1]);
}