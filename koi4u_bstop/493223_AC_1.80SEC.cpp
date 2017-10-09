#include<stdio.h>
#include<algorithm>
#define MOD 1000000007
using namespace std;
long long N,M;
struct A {
	long long start,end,key[2];
	bool operator<(const A &a) const {
		if(end ==a.end) return start<a.start;
		return end < a.end;
	}
}station[111111];
struct B {
	long long su,startend,ind;
	bool operator<(const B &b) const {
		return su < b.su;
	}
}sorted[222222];
long long tree[600000];
long long D[100011];
long long cnt;
int main() {
	scanf("%lld%lld",&N,&M);
	long long i;
	sorted[++cnt].su=0;
	sorted[cnt].ind=0;
	sorted[cnt].startend=1;
	for(i=1;i<=M;i++) {
		scanf("%lld%lld",&station[i].start,&station[i].end);
	}
	stable_sort(station+1,station+1+M);
	for(i=1;i<=M;i++) {
		sorted[++cnt].su=station[i].start;
		sorted[cnt].startend=0;
		sorted[cnt].ind=i;
		//
		sorted[++cnt].su=station[i].end;
		sorted[cnt].startend=1;
		sorted[cnt].ind=i;
	}
	stable_sort(sorted+1,sorted+1+cnt);
	long long lank=1;
	for(i=1;i<=cnt;i++) {
		if(sorted[i-1].su != sorted[i].su) lank++;
		station[sorted[i].ind].key[sorted[i].startend]=lank;
	}
	long long size=1;
	for(;size<lank;size*=2);
	long long tr=size+1;
	while(tr>0) {
		tree[tr]+=1;
		tree[tr]%=MOD;
		tr/=2;
	}
	for(i=1;i<=M;i++) {
		long long ls=size+station[i].key[0],rs=size+station[i].key[1]-1;
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
		rs=size+station[i].key[1];
		while(rs>0) {
			tree[rs]+=sum;
			tree[rs]%=MOD;
			rs/=2;
		}
		D[i]=sum;
	}
	long long ans=0;
	for(i=1;i<=M;i++) {
		if(station[i].end==N) ans+=D[i];
		ans%=MOD;
	}
	printf("%lld",ans);
}