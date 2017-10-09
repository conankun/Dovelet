#include<stdio.h>
#include<algorithm>
using namespace std;
struct CMP {
	bool operator() (long long a,long long b) {
		if(a<b) return true;
		return false;
	}
};
struct cows {
	long long SAT,finance;
	bool operator<(const cows &cow) const {
		if(cow.SAT == SAT) return finance < cow.finance;
		return SAT < cow.SAT;
	}
}cow[100001];
long long n,c,f;
long long top_bottom[100001],bottom_up[100001],sum[100001];
long long Heap_1[100001],Heap_2[100001];
int main() {
	scanf("%lld%lld%lld",&n,&c,&f);
	long long i;
	for(i=1;i<=c;i++) {
		scanf("%lld%lld",&cow[i].SAT,&cow[i].finance);
	}
	stable_sort(cow+1,cow+1+c);
	for(i=1;i<=c;i++) sum[i] = sum[i-1]+cow[i].finance;
	long long N=1;
	make_heap(Heap_1,Heap_1+N,CMP());
	for(i=1;i<=n/2;i++) {
		top_bottom[i] = 2147483647;
		Heap_1[N]=cow[i].finance;
		N++;
		push_heap(Heap_1,Heap_1+N,CMP());
	}
	top_bottom[n/2] = sum[n/2]-sum[0];
	for(i=n/2+1;i<=c;i++) {
		Heap_1[N] = cow[i].finance;
		N++;
		push_heap(Heap_1,Heap_1+N,CMP());
		long long pop = Heap_1[0];
		pop_heap(Heap_1,Heap_1+N,CMP());
		N--;
		top_bottom[i] = top_bottom[i-1]+cow[i].finance-pop;
	}
	N=1;
	for(i=c;i>=c-n/2+1;i--) {
		bottom_up[i] = 2147483647;
		Heap_2[N]=cow[i].finance;
		N++;
		push_heap(Heap_2,Heap_2+N,CMP());
	}
	bottom_up[c-n/2+1] = sum[c]-sum[c-n/2];
	for(i=c-n/2;i>=1;i--) {
		Heap_2[N] = cow[i].finance;
		N++;
		push_heap(Heap_2,Heap_2+N,CMP());
		long long pop = Heap_2[0];
		pop_heap(Heap_2,Heap_2+N,CMP());
		N--;
		bottom_up[i] = bottom_up[i+1]+cow[i].finance-pop;
	}
	long long ans=-1;
	for(i=n/2+1;i<=c-n/2;i++) {
		if(top_bottom[i-1]+bottom_up[i+1]+cow[i].finance <= f) {
			ans = cow[i].SAT;
		}
	}
	 printf("%lld",ans);
}