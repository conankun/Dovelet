#include<stdio.h>
#include<algorithm>
#define MOD 1000000009
long long cow[100001];
long long N;
long long tree[300000];
long long D[100001];
struct A {
	long long ind,value;
	bool operator<(const A &a) const {
		return value < a.value;
	}
}keysort[111111];
long long key[111111];
int main() {
	scanf("%lld",&N);
	long long i;
	keysort[1].value = 0;
	keysort[1].ind = 1;
	for(i=2;i<=N+1;i++) {
		scanf("%lld",&cow[i]);
		cow[i]+=cow[i-1];
		keysort[i].value = cow[i];
		keysort[i].ind = i;
	}
	std::stable_sort(keysort+1,keysort+1+N+1);
	long long lank=0;
	keysort[0].value = -1231321113124LL;
	for(i=1;i<=N+1;i++) {
		if(keysort[i].value != keysort[i-1].value) lank++;
		key[keysort[i].ind]=lank;
	}
	long long size=1;
	for(;size<N;size*=2);
	D[1]=1;
	for(i=1;i<=N+1;i++) {
		long long ls=size+1,rs=size+key[i];
		bool ok=true;
		long long sum=0;
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
	printf("%lld",D[N+1]);
}