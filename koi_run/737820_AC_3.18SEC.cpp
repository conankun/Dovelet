#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
int ab[1000000];
int key[1000000];
int print[1000000];
struct A {
	int num,value;
}sortarr[1000000];
bool cmp(A a, A b) {
	if(a.value > b.value) return false;
	return true;
}
int tree[1111111];
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) {
		scanf("%d",&ab[i]);
		sortarr[i].num = i;
		sortarr[i].value = ab[i];
	}
	sort(sortarr+1,sortarr+1+n,cmp);
	for(i=1;i<=n;i++) {
		key[sortarr[i].num]=i;
	}
	int size=1;
	while(size<=n) size*=2;
	for(i=1;i<=n;i++) {
		int ls=1+size, rs= key[i]+size,ok=1,sum=0;
		while(ls<=rs && ok) {
			if(ls%2==1) {
				sum+=tree[ls];
				ls++;
			}
			if(rs%2==0) {
				sum+=tree[rs];
				rs--;
			}
			if(ls==rs) ok = 0;
			ls/=2;
			rs/=2;
		}
		print[i]=sum;
		rs=key[i]+size;
		while(rs > 0) {
			tree[rs]+=1;
			rs/=2;
		}
	}
	for(i=1;i<=n;i++) {
		printf("%d\n",i-print[i]);
	}
}